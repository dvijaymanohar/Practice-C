                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : FreeWare ANSI-C Compiler
                              3 ; Version 2.6.0 #4309 (Sep 29 2006)
                              4 ; This file generated Tue Jan 16 09:02:49 2007
                              5 ;--------------------------------------------------------
                              6 	.module led
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _PORT0
                             14 	.globl _delay
                             15 ;--------------------------------------------------------
                             16 ; special function registers
                             17 ;--------------------------------------------------------
                             18 	.area RSEG    (DATA)
                    0080     19 _PORT0	=	0x0080
                             20 ;--------------------------------------------------------
                             21 ; special function bits
                             22 ;--------------------------------------------------------
                             23 	.area RSEG    (DATA)
                             24 ;--------------------------------------------------------
                             25 ; overlayable register banks
                             26 ;--------------------------------------------------------
                             27 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                      28 	.ds 8
                             29 ;--------------------------------------------------------
                             30 ; internal ram data
                             31 ;--------------------------------------------------------
                             32 	.area DSEG    (DATA)
                             33 ;--------------------------------------------------------
                             34 ; overlayable items in internal ram 
                             35 ;--------------------------------------------------------
                             36 	.area	OSEG    (OVR,DATA)
                             37 ;--------------------------------------------------------
                             38 ; Stack segment in internal ram 
                             39 ;--------------------------------------------------------
                             40 	.area	SSEG	(DATA)
   0008                      41 __start__stack:
   0008                      42 	.ds	1
                             43 
                             44 ;--------------------------------------------------------
                             45 ; indirectly addressable internal ram data
                             46 ;--------------------------------------------------------
                             47 	.area ISEG    (DATA)
                             48 ;--------------------------------------------------------
                             49 ; bit data
                             50 ;--------------------------------------------------------
                             51 	.area BSEG    (BIT)
                             52 ;--------------------------------------------------------
                             53 ; paged external ram data
                             54 ;--------------------------------------------------------
                             55 	.area PSEG    (PAG,XDATA)
                             56 ;--------------------------------------------------------
                             57 ; external ram data
                             58 ;--------------------------------------------------------
                             59 	.area XSEG    (XDATA)
                             60 ;--------------------------------------------------------
                             61 ; external initialized ram data
                             62 ;--------------------------------------------------------
                             63 	.area XISEG   (XDATA)
                             64 	.area HOME    (CODE)
                             65 	.area GSINIT0 (CODE)
                             66 	.area GSINIT1 (CODE)
                             67 	.area GSINIT2 (CODE)
                             68 	.area GSINIT3 (CODE)
                             69 	.area GSINIT4 (CODE)
                             70 	.area GSINIT5 (CODE)
                             71 	.area GSINIT  (CODE)
                             72 	.area GSFINAL (CODE)
                             73 	.area CSEG    (CODE)
                             74 ;--------------------------------------------------------
                             75 ; interrupt vector 
                             76 ;--------------------------------------------------------
                             77 	.area HOME    (CODE)
   0000                      78 __interrupt_vect:
   0000 02 00 03             79 	ljmp	__sdcc_gsinit_startup
                             80 ;--------------------------------------------------------
                             81 ; global & static initialisations
                             82 ;--------------------------------------------------------
                             83 	.area HOME    (CODE)
                             84 	.area GSINIT  (CODE)
                             85 	.area GSFINAL (CODE)
                             86 	.area GSINIT  (CODE)
                             87 	.globl __sdcc_gsinit_startup
                             88 	.globl __sdcc_program_startup
                             89 	.globl __start__stack
                             90 	.globl __mcs51_genXINIT
                             91 	.globl __mcs51_genXRAMCLEAR
                             92 	.globl __mcs51_genRAMCLEAR
                             93 	.area GSFINAL (CODE)
   005C 02 00 5F             94 	ljmp	__sdcc_program_startup
                             95 ;--------------------------------------------------------
                             96 ; Home
                             97 ;--------------------------------------------------------
                             98 	.area HOME    (CODE)
                             99 	.area CSEG    (CODE)
   005F                     100 __sdcc_program_startup:
   005F 12 00 64            101 	lcall	_main
                            102 ;	return from main will lock up
   0062 80 FE               103 	sjmp .
                            104 ;--------------------------------------------------------
                            105 ; code
                            106 ;--------------------------------------------------------
                            107 	.area CSEG    (CODE)
                            108 ;------------------------------------------------------------
                            109 ;Allocation info for local variables in function 'main'
                            110 ;------------------------------------------------------------
                            111 ;------------------------------------------------------------
                            112 ;	led.c:4: int main()
                            113 ;	-----------------------------------------
                            114 ;	 function main
                            115 ;	-----------------------------------------
   0064                     116 _main:
                    0002    117 	ar2 = 0x02
                    0003    118 	ar3 = 0x03
                    0004    119 	ar4 = 0x04
                    0005    120 	ar5 = 0x05
                    0006    121 	ar6 = 0x06
                    0007    122 	ar7 = 0x07
                    0000    123 	ar0 = 0x00
                    0001    124 	ar1 = 0x01
                            125 ;	led.c:6: PORT0 = 0xFF;
                            126 ;	genAssign
   0064 75 80 FF            127 	mov	_PORT0,#0xFF
                            128 ;	led.c:7: while(1)
   0067                     129 00102$:
                            130 ;	led.c:11: delay();
                            131 ;	genCall
   0067 12 00 75            132 	lcall	_delay
                            133 ;	led.c:12: PORT0 = PORT0<<1 ;
                            134 ;	genLeftShift
                            135 ;	genLeftShiftLiteral
                            136 ;	genlshOne
   006A E5 80               137 	mov	a,_PORT0
   006C 25 E0               138 	add	a,acc
   006E F5 80               139 	mov	_PORT0,a
                            140 ;	led.c:13: delay();
                            141 ;	genCall
   0070 12 00 75            142 	lcall	_delay
                            143 ;	Peephole 112.b	changed ljmp to sjmp
   0073 80 F2               144 	sjmp	00102$
                            145 ;	Peephole 259.a	removed redundant label 00104$ and ret
                            146 ;
                            147 ;------------------------------------------------------------
                            148 ;Allocation info for local variables in function 'delay'
                            149 ;------------------------------------------------------------
                            150 ;i                         Allocated to registers r2 r3 
                            151 ;------------------------------------------------------------
                            152 ;	led.c:17: void delay(void)
                            153 ;	-----------------------------------------
                            154 ;	 function delay
                            155 ;	-----------------------------------------
   0075                     156 _delay:
                            157 ;	led.c:20: for(i = 0; i < 30000; i++);
                            158 ;	genAssign
   0075 7A 30               159 	mov	r2,#0x30
   0077 7B 75               160 	mov	r3,#0x75
   0079                     161 00103$:
                            162 ;	genMinus
                            163 ;	genMinusDec
   0079 1A                  164 	dec	r2
   007A BA FF 01            165 	cjne	r2,#0xff,00109$
   007D 1B                  166 	dec	r3
   007E                     167 00109$:
                            168 ;	genIfx
   007E EA                  169 	mov	a,r2
   007F 4B                  170 	orl	a,r3
                            171 ;	genIfxJump
                            172 ;	Peephole 108.b	removed ljmp by inverse jump logic
   0080 70 F7               173 	jnz	00103$
                            174 ;	Peephole 300	removed redundant label 00110$
                            175 ;	Peephole 300	removed redundant label 00104$
   0082 22                  176 	ret
                            177 	.area CSEG    (CODE)
                            178 	.area CONST   (CODE)
                            179 	.area XINIT   (CODE)
