/**
  ******************************************************************************************************************
  * @file    bmpTuture.c 
  * @author  T.HAYS et F.MORNET     IUT Informatique La Rochelle
  * @version v1.3
  * @date    11 mai 2017
  * @modification ajout des bitmaps des sprites des voitures
  * @brief   définitions pour la description du bitmap d'une voiture
  ******************************************************************************************************************/

#include "ext_globales.h"
#include "GLCD_Config.h"
#include "bmpTuture.h"

const unsigned short bmptuturehautpng[10*18]=
{
	0x0000,0x0000,0x738E,0x0AC0,0x0AC0,0x0AC0,0x0AC0,0x738E,0x0000,0x0000,
	0x0000,0x738E,0xF76D,0x738E,0x738E,0x738E,0x738E,0xF76D,0x738E,0x0000,
	0x0000,0x738E,0xF322,0x65AA,0x65AA,0x65AA,0x65AA,0xF322,0x738E,0x0000,
	0x0000,0x33C4,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7E2E,0x0000,
	0x0000,0x33C4,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7E2E,0x0000,
	0x0000,0x33C4,0x65AA,0x65AA,0x738E,0x738E,0x65AA,0x65AA,0x7E2E,0x0000,
	0x0000,0x738E,0x577D,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x738E,0x0000,
	0x738E,0x738E,0x577D,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0xF7BE,0x738E,0x738E,
	0x0000,0x7FFF,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7FFF,0x0000,
	0x0000,0x7FFF,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7E2E,0x7FFF,0x0000,
	0x0000,0x7FFF,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7E2E,0x7FFF,0x0000,
	0x0000,0x7FFF,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7FFF,0x0000,
	0x0000,0x7FFF,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7FFF,0x0000,
	0x0000,0x7FFF,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7E2E,0x7FFF,0x0000,
	0x0000,0x33C4,0x33C4,0x33C4,0x65AA,0x65AA,0x7E2E,0x7E2E,0x7E2E,0x0000,
	0x0000,0x33C4,0x33C4,0x65AA,0x65AA,0x65AA,0x65AA,0x7E2E,0x7E2E,0x0000,
	0x0000,0x33C4,0x33C4,0x65AA,0x65AA,0x65AA,0x65AA,0x7E2E,0x7E2E,0x0000,
	0x0000,0x0000,0x33C4,0x33C4,0x65AA,0x65AA,0x7E2E,0x7E2E,0x0000,0x0000
};

const unsigned short bmptuturebaspng[10*18]=
{
	0x0000,0x0000,0x738E,0x0AC0,0x0AC0,0x0AC0,0x0AC0,0x738E,0x0000,0x0000,
	0x0000,0x738E,0xF76D,0x738E,0x738E,0x738E,0x738E,0xF76D,0x738E,0x0000,
	0x0000,0x738E,0xF322,0x65AA,0x65AA,0x65AA,0x65AA,0xF322,0x738E,0x0000,
	0x0000,0x33C4,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7E2E,0x0000,
	0x0000,0x33C4,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7E2E,0x0000,
	0x0000,0x33C4,0x65AA,0x65AA,0x738E,0x738E,0x65AA,0x65AA,0x7E2E,0x0000,
	0x0000,0x738E,0x577D,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x738E,0x0000,
	0x738E,0x738E,0x577D,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0xF7BE,0x738E,0x738E,
	0x0000,0x7FFF,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7FFF,0x0000,
	0x0000,0x7FFF,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7E2E,0x7FFF,0x0000,
	0x0000,0x7FFF,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7E2E,0x7FFF,0x0000,
	0x0000,0x7FFF,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7FFF,0x0000,
	0x0000,0x7FFF,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7FFF,0x0000,
	0x0000,0x7FFF,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7E2E,0x7FFF,0x0000,
	0x0000,0x33C4,0x33C4,0x33C4,0x65AA,0x65AA,0x7E2E,0x7E2E,0x7E2E,0x0000,
	0x0000,0x33C4,0x33C4,0x65AA,0x65AA,0x65AA,0x65AA,0x7E2E,0x7E2E,0x0000,
	0x0000,0x33C4,0x33C4,0x65AA,0x65AA,0x65AA,0x65AA,0x7E2E,0x7E2E,0x0000,
	0x0000,0x0000,0x33C4,0x33C4,0x65AA,0x65AA,0x7E2E,0x7E2E,0x0000,0x0000
};

const unsigned short bmptuturedroitepng[18*10]=
{
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x738E,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x33C4,0x33C4,0x33C4,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x738E,0x738E,0x33C4,0x33C4,0x33C4,0x738E,0x738E,0x0000,
	0x33C4,0x33C4,0x33C4,0x33C4,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x577D,0x577D,0x65AA,0x65AA,0x65AA,0xF322,0xF76D,0x738E,
	0x33C4,0x65AA,0x65AA,0x33C4,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7FFF,0x7FFF,0x65AA,0x65AA,0x65AA,0x65AA,0x738E,0x0AC0,
	0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7FFF,0x7FFF,0x738E,0x65AA,0x65AA,0x65AA,0x738E,0x0AC0,
	0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7FFF,0x7FFF,0x738E,0x65AA,0x65AA,0x65AA,0x738E,0x0AC0,
	0x7E2E,0x65AA,0x65AA,0x7E2E,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7FFF,0x7FFF,0x65AA,0x65AA,0x65AA,0x65AA,0x738E,0x0AC0,
	0x7E2E,0x7E2E,0x7E2E,0x7E2E,0x7E2E,0x65AA,0x65AA,0x7E2E,0x7E2E,0x65AA,0xF7BE,0x7FFF,0x65AA,0x65AA,0x65AA,0xF322,0xF76D,0x738E,
	0x0000,0x7E2E,0x7E2E,0x7E2E,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x738E,0x738E,0x7E2E,0x7E2E,0x7E2E,0x738E,0x738E,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x738E,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
};

const unsigned short bmptuturegauchepng[18*10]=
{
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x738E,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x738E,0x738E,0x7E2E,0x7E2E,0x7E2E,0x738E,0x738E,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7E2E,0x7E2E,0x7E2E,0x0000,
	0x738E,0xF76D,0xF322,0x65AA,0x65AA,0x65AA,0x7FFF,0xF7BE,0x65AA,0x7E2E,0x7E2E,0x65AA,0x65AA,0x7E2E,0x7E2E,0x7E2E,0x7E2E,0x7E2E,
	0x0AC0,0x738E,0x65AA,0x65AA,0x65AA,0x65AA,0x7FFF,0x7FFF,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x7E2E,0x65AA,0x65AA,0x7E2E,
	0x0AC0,0x738E,0x65AA,0x65AA,0x65AA,0x738E,0x7FFF,0x7FFF,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,
	0x0AC0,0x738E,0x65AA,0x65AA,0x65AA,0x738E,0x7FFF,0x7FFF,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,
	0x0AC0,0x738E,0x65AA,0x65AA,0x65AA,0x65AA,0x7FFF,0x7FFF,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x33C4,0x65AA,0x65AA,0x33C4,
	0x738E,0xF76D,0xF322,0x65AA,0x65AA,0x65AA,0x577D,0x577D,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x65AA,0x33C4,0x33C4,0x33C4,0x33C4,
	0x0000,0x738E,0x738E,0x33C4,0x33C4,0x33C4,0x738E,0x738E,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x33C4,0x33C4,0x33C4,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x738E,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
};