#include "iodefine.h"

void init_port(void);

void main(void)
{
	init_port( );
	SYSTEM.PRCR.WORD = 0xA502;
	MSTP( CMT0 ) = 0;
	SYSTEM.PRCR.WORD = 0xA500;
	CMT0.CMCOR = 29900;
	CMT0.CMCR.WORD = 0x0040;
	IPR( CMT0, CMI0 ) = 1;
	IEN( CMT0, CMI0 ) = 1;
	CMT.CMSTR0.BIT.STR0 = 1;
	__setpsw_i( );
	while( 1 )  ;
}

void init_port(void)
{
	PORT4.PDR.BIT.B0 = 1;
}

#pragma interrupt CMI0(vect=VECT(CMT0,CMI0))
void CMI0(void)
{
	PORT4.PODR.BIT.B0 ^= 1;
}