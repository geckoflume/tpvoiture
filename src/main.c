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

void cfgTimer1(void){
	 RCC->APB2ENR |= (1<<11);
	 TIM1->PSC=59;
	 TIM1->ARR=60000;
	 TIM1->DIER |= (1<<0);
	 TIM1->CR1 |= 0x0001;
	 *(volatile unsigned long *)0xE000E100 |= (1<<25);
 }
 
 // Traitement de l'interruption sur le timer TIM1
 void TIM1_UP_TIM10_IRQHandler(void){
	 if(TIM1->SR & UIF)
	 {
		 TIM1->SR &= ~UIF;
		 voiture.y--;
	 }
 }
 
 void clearVoiture(int x, int y){
	GLCD_DrawBargraph(x, y, wbmpTuture, hbmpTuture, 0);
 }
 
/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
int main (void) {
	voiture.x = 100;
	voiture.y = 0;
	voitureOld = voiture;
	voitureOld.y--;
	
  	GLCD_Initialize();                          /* Initialize graphical LCD display   */
  	GLCD_SetBackgroundColor(GLCD_COLOR_BLACK);
	GLCD_SetForegroundColor(GLCD_COLOR_WHITE);
	GLCD_ClearScreen(); 
	
	cfgTimer1();
	
	while(1)
	{
		if(voitureOld.x!=voiture.x || voitureOld.y!=voiture.y){
			clearVoiture(voitureOld.x, voitureOld.y);
			GLCD_DrawBitmap(voiture.x, voiture.y, wbmpTuture, hbmpTuture, (const unsigned char *)bmpTuture);
			voitureOld = voiture;
		}
	}
}
