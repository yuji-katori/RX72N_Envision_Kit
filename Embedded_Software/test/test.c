#include "iodefine.h"

void main(void)
{
	PORT4.PDR.BIT.B0 = 1;
	while( 1 )
		PORT4.PODR.BIT.B0 = PORT0.PIDR.BIT.B7;
}