/**
  ******************************************************************************************************************
  * @file    ext_globales.h 
  * @author  T.HAYS et F.MORNET     IUT Informatique La Rochelle
  * @version v1.2
  * @date    11 mai 2017
  * @modification	ajout des d�clarations des voitures
  * @brief   d�clarations des variables globales
  ******************************************************************************************************************/

#ifndef __EXT_GLOBALES_H
#define __EXT_GLOBALES_H

#include "Board_GLCD.h"
#include "Voiture.h"

extern GLCD_FONT GLCD_Font_6x8;
extern GLCD_FONT GLCD_Font_16x24;

extern Voiture voiture;
extern Voiture voitureOld;

#endif
