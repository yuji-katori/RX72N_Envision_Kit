#pragma stacksize si=0x400
#pragma entry PowerON_Reset
void PowerON_Reset(void)
{
	__set_intb(__sectop("C$VECT"));
	*(int*)0 = 1;
	main( );
}

#pragma section C RESETVECT
void (* const Reset_Vectors[])(void) = {
	PowerON_Reset
};

#pragma address __MDEreg=0xfe7f5d00
#ifdef __BIG
	const unsigned long __MDEreg = 0xfffffff8;
#else
	const unsigned long __MDEreg = 0xffffffff;
#endif

#pragma address __OFS0reg=0xfe7f5d04
const unsigned long __OFS0reg = 0xffffffff;

#pragma address __OFS1reg=0xfe7f5d08
const unsigned long __OFS1reg = 0xffffffff;

#pragma address __TMINFreg=0xfe7f5d10
const unsigned long __TMINFreg = 0xffffffff;

#pragma address __SPCCreg=0xfe7f5d40
const unsigned long __SPCCreg = 0xffffffff;

#pragma address __TMEFreg=0xfe7f5d48
const unsigned long __TMEFreg = 0xffffffff;

#pragma address __OSISreg=0xfe7f5d50
const unsigned long __OSISreg[4] = {
        0xffffffff,
        0xffffffff,
        0xffffffff,
        0xffffffff,
};

#pragma address __FAWreg=0xfe7f5d64
const unsigned long __FAWreg = 0xffffffff;

#pragma address __RCPreg=0xfe7f5d70
const unsigned long __RCPreg = 0xffffffff;