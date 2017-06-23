/**
  ******************************************************************************************************************
  * @file    main.c 
  * @author  R.NOHE     IUT Informatique La Rochelle
  * @version v1.1
  * @date    11 mai 2017
  * @modification	rien pour le moment
  * @brief   template pour piloter l'afficheur LCD des cartes MCBSTM32EXL
  ******************************************************************************************************************/

#include "stm32f10x.h"                  /* STM32F10x.h definitions */
#include "GLCD_Config.h"
#include "bmpTuture.h"
#include "ext_globales.h"
#include "globales.h"
#include "Voiture.h"

#define UIF (1<<0)
#define SETENA0 *(volatile unsigned long *)0xE000E100
#define SETENA1 *(volatile unsigned long *)0xE000E104
#define AFIO_EXTICR1 *(volatile unsigned long *)0x40010008
#define AFIO_EXTICR4 *(volatile unsigned long *)0x40010014

bool bordureTouchee = 0;
bool desactiverJoystickDown = 0;
bool desactiverJoystickUp = 0;

void cfgTimer1(void){
	 RCC->APB2ENR |= (1<<11);
	 TIM1->PSC=59;
	 TIM1->ARR=60000;
	 TIM1->DIER |= (1<<0);
	 TIM1->CR1 |= 0x0001;
	 *(volatile unsigned long *)0xE000E100 |= (1<<25);
 }

 void cfgGPIO(void){
	 unsigned int temp;
	 
	 // Mise en place des registres AFIO pour la configuration d'interruptions externes
	 RCC->APB2ENR |= (1<<0); //Enable AFIO Clock
	 
	 // Configuration de JOYSTICK_UP sur PG15
	 RCC->APB2ENR |= (1<<8); //Activation du GPIOG
	 temp = GPIOG->CRH & 0x0FFFFFFF;
	 GPIOG->CRH = temp | 0x40000000;
	 
	 // Configuration des ISR sur EXT15 (JOYSTICK_UP)
	 SETENA1 |= (1<<8); // bit 8 pour activation IRQ EXT15
	 temp = AFIO_EXTICR4 & 0x0FFF;
	 AFIO_EXTICR4 = temp | 0x6000; // multiplexeur connectant PG15 sur EXTI15_10
	 EXTI->IMR |= (1<<15); // interrupt mask
	 EXTI->FTSR |= (1<<15); //event sur front descendant autorisé
	 
	 // Configuration de JOYSTICK_DOWN sur PD3
   	 RCC->APB2ENR |= (1<<5); //Activation du GPIOD
	 temp = GPIOD->CRH & 0xFFFFF0FF;
	 GPIOD->CRH = temp | 0x00000400;

	 // Configuration des ISR sur EXTI3 (JOYSTICK_DOWN)
     SETENA0 |= (1<<9); // bit 9 pour activation IRQ EXTI3
     temp = AFIO_EXTICR1 & 0x0FFF;
     AFIO_EXTICR1 = temp | 0x3000; // multiplexeur connectant PG13 sur EXTI3
     EXTI->IMR |= (1<<3); // interrupt mask
     EXTI->FTSR |= (1<<3); //event sur front descendant autorisé

	// Configuration de BP_WAKEUP sur PD3
	RCC->APB2ENR |= (1<<2); //Activation du GPIOD
	temp = GPIOA->CRL & 0xFFFFFFF0;
    GPIOA->CRL = temp | 0x00000004;

	// Configuration des ISR sur EXTI0 (BP_WAKEUP)
	SETENA0 |= (1<<6); // bit 6 pour activation IRQ EXTI0
	AFIO_EXTICR1 &= 0xFFF0;
	EXTI->IMR |= (1<<0); // interrupt mask
	EXTI->RTSR |= (1<<0); //event sur front descendant autorisé
	
	// Configuration de BP_TAMPER sur PC13
	RCC->APB2ENR |= (1<<4); //Activation du GPIOC
	temp = GPIOC->CRH & 0xFF0FFFFF;
    GPIOC->CRH = temp | 0x00400000;

	// Configuration des ISR sur EXTI13 (BP_TAMPER)
	temp = AFIO_EXTICR4 & 0xFF0F;
	AFIO_EXTICR4 = temp | 0x0020;
	EXTI->IMR |= (1<<13); // interrupt mask
	EXTI->FTSR |= (1<<13); //event sur front descendant autorisé
 }
 
 // Traitement de l'interruption sur le timer TIM1
 void TIM1_UP_TIM10_IRQHandler(void){
	 if(TIM1->SR & UIF)
	 {
		 TIM1->SR &= ~UIF;
		 if(voiture.vitesse!=0&&(voiture.y<=0||voiture.y==240-18)){
			 if(voiture.y<0){
				voiture.y=0;
			 }
				bordureTouchee = 0;
				voiture.vitesse = 0;
		 }else{
		 voiture.y-=voiture.vitesse;
		}
		 if(voiture.y==240-18){
			 desactiverJoystickDown=1;
		 } else if(voiture.y<=0){
			 desactiverJoystickUp=1;
 }

 // Traitement de l'interruption sur PG15
  void EXTI15_10_IRQHandler(void){
		if(EXTI->PR & (1<<15)){
			EXTI->PR |=(1<<15);
			if(voiture.vitesse < 5 && desactiverJoystickUp==0){
				if(bordureTouchee==0){
					voiture.y-=2;
					bordureTouchee=1;
					desactiverJoystickDown=0;
				}
				voiture.vitesse++;
			}
		}
		if(EXTI->PR & (1<<13)){
			EXTI->PR |=(1<<13);
			if(voiture.vitesse < 5){
				//voiture.vitesse--;
			}
		}
	}
	
// Traitement de l'interruption sur PD3
  void EXTI3_IRQHandler(void){
		if(EXTI->PR & (1<<3)){
			EXTI->PR |=(1<<3);
			if(voiture.vitesse > -1 && desactiverJoystickDown==0){
				if(bordureTouchee==0){
					voiture.y+=2;
					bordureTouchee=1;
					desactiverJoystickUp=0;
				}
				voiture.vitesse--;
			}
		}
	}
 
 void clearVoiture(int x, int y){
	GLCD_DrawBargraph(x, y, wbmpTuture, hbmpTuture, 0);
 }
 
/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
int main (void) {
	voiture.x = 150;
	voiture.y = 240-18;
	voiture.vitesse = 0;
	voitureOld = voiture;
	voitureOld.y--;
	voiture.sprite = bmptuturehautpng;
	
    GLCD_Initialize();                          /* Initialize graphical LCD display */
    GLCD_SetBackgroundColor(GLCD_COLOR_BLACK);
	GLCD_SetForegroundColor(GLCD_COLOR_WHITE);
	GLCD_ClearScreen(); 
	
	cfgTimer1();
	cfgGPIO();
	GLCD_SetFont(&GLCD_Font_6x8);
	
	GLCD_DrawChar(307,230,' ');
	GLCD_DrawChar(310,230,(char)48);
	
	while(1)
    {
		if(voitureOld.x!=voiture.x || voitureOld.y!=voiture.y || voitureOld.vitesse!=voiture.vitesse){
			clearVoiture(voitureOld.x, voitureOld.y);
			GLCD_DrawBitmap(voiture.x, voiture.y, wbmpTuture, hbmpTuture, (const unsigned char *)voiture.sprite);
			
			if(voitureOld.vitesse!=voiture.vitesse){
						if(voiture.vitesse+48==47){
							GLCD_DrawChar(307,230,'-');
							GLCD_DrawChar(310,230,'1');
						}else{
							GLCD_DrawChar(307,230,' ');
							GLCD_DrawChar(310,230,(char)voiture.vitesse+48);
						}
					}
			
			voitureOld = voiture;
								
										  
		}
	}
}
