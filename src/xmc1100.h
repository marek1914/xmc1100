// xmc1100.h

// LPC low level all-in-one header file for Infineon XMC1100
// principally targeted at xmc-2go dev kit
// Written by Frank Duignan
// Latest version available at http://eleceng.dit.ie/frank/arm/cortex/xmc1100.h
// Derived from XMC1100 Reference manual from Infineon
// Naming convention: Register names are as described in Reference Manual
// Initial version did not include debug registers (may change in future)
// In the case of peripheral registers, the peripheral name is pre-pended e.g.
// WDT_ID is used rather than ID which might conflict with some other system
// No claims are made for the suitability, accuracy or otherwise of this file
// for any application
// Define some bitmasks

#ifndef PERIPHERALS_XMC1100_H
#define PERIPHERALS_XMC1100_H

#define BIT0 (1 << 0)
#define BIT1 (1 << 1)
#define BIT2 (1 << 2)
#define BIT3 (1 << 3)
#define BIT4 (1 << 4)
#define BIT5 (1 << 5)
#define BIT6 (1 << 6)
#define BIT7 (1 << 7)
#define BIT8 (1 << 8)
#define BIT9 (1 << 9)
#define BIT10 (1 << 10)
#define BIT11 (1 << 11)
#define BIT12 (1 << 12)
#define BIT13 (1 << 13)
#define BIT14 (1 << 14)
#define BIT15 (1 << 15)
#define BIT16 (1 << 16)
#define BIT17 (1 << 17)
#define BIT18 (1 << 18)
#define BIT19 (1 << 19)
#define BIT20 (1 << 20)
#define BIT21 (1 << 21)
#define BIT22 (1 << 22)
#define BIT23 (1 << 23)
#define BIT24 (1 << 24)
#define BIT25 (1 << 25)
#define BIT26 (1 << 26)
#define BIT27 (1 << 27)
#define BIT28 (1 << 28)
#define BIT29 (1 << 29)
#define BIT30 (1 << 30)
#define BIT31 (1 << 31)

// Macros to reduce typing later on
#define  REGISTER_32(ADDRESS) (*((volatile unsigned int *const)(ADDRESS)))
#define  REGISTER_16(ADDRESS) (*((volatile unsigned int *const)(ADDRESS)))
#define  PTR_32(ADDRESS) (((volatile unsigned int *)(ADDRESS)))

// Macros to enable/disable global interrupts
#define enable_interrupts() asm(" cpsie i ")
#define disable_interrupts() asm(" cpsid i ")

#define NVIC_BASE 		0xe000e100
#define SCS_BASE		0xe000ed00
#define STK_BASE		0xe000e010
#define WDT_BASE 		0x40020000
#define RTC_BASE 		0x40010a00
#define SCU_BASE 		0x40010000
#define TSE_BASE		0x40010000
#define ERU0_BASE		0x40010600
#define PAU_BASE		0X40000000
#define PRNG_BASE 		0x48020000
#define USIC0_CH0_BASE 		0x48000000
#define USIC0_CH1_BASE 		0x48000200
#define VADC0_BASE		0x48030000
#define SHS0_BASE		0x48034000
#define CCU40_BASE		0x48040000
#define P0_BASE			0x40040000
#define P1_BASE			0x40040100
#define P2_BASE			0x40040200
#define NVM_BASE		0x40050000

// NVIC
#define NVIC_ISER		REGISTER_32(NVIC_BASE + 0)
#define NVIC_ICER		REGISTER_32(NVIC_BASE + 0x80)
#define NVIC_ISPR		REGISTER_32(NVIC_BASE + 0x100)
#define NVIC_ICPR		REGISTER_32(NVIC_BASE + 0x180)
#define NVIC_IPR0		REGISTER_32(NVIC_BASE + 0x300)
#define NVIC_IPR1		REGISTER_32(NVIC_BASE + 0x304)
#define NVIC_IPR2		REGISTER_32(NVIC_BASE + 0x308)
#define NVIC_IPR3		REGISTER_32(NVIC_BASE + 0x30c)
#define NVIC_IPR4		REGISTER_32(NVIC_BASE + 0x310)
#define NVIC_IPR5		REGISTER_32(NVIC_BASE + 0x314)
#define NVIC_IPR6		REGISTER_32(NVIC_BASE + 0x318)
#define NVIC_IPR7		REGISTER_32(NVIC_BASE + 0x31c)

// SCS
#define CPUID			REGISTER_32(SCS_BASE + 0)
#define SCS_ICSR		REGISTER_32(SCS_BASE + 0x04)
#define SCS_AIRCR		REGISTER_32(SCS_BASE + 0x0c)
#define SCS_SCR			REGISTER_32(SCS_BASE + 0x10)
#define SCS_CCR			REGISTER_32(SCS_BASE + 0x14)
#define SCS_SHPR2		REGISTER_32(SCS_BASE + 0x1c)
#define SCS_SHPR3		REGISTER_32(SCS_BASE + 0x20)
#define SCS_SHCSR		REGISTER_32(SCS_BASE + 0x24)

// STK
#define SYST_CSR		REGISTER_32(STK_BASE + 0)
#define SYST_RVR		REGISTER_32(STK_BASE + 4)
#define SYST_CVR		REGISTER_32(STK_BASE + 8)
#define SYST_CALIB		REGISTER_32(STK_BASE + 0x0c)

// Flash
#define NVMSTATUS		REGISTER_32(NVM_BASE + 0x00)
#define NVMPROG			REGISTER_32(NVM_BASE + 0x04)
#define NVMCONF			REGISTER_32(NVM_BASE + 0x08)

// ERU
#define EXISEL			REGISTER_32(ERU0_BASE + 0x00)
#define EXICON0			REGISTER_32(ERU0_BASE + 0x10)
#define EXICON1			REGISTER_32(ERU0_BASE + 0x14)
#define EXICON2			REGISTER_32(ERU0_BASE + 0x18)
#define EXICON3			REGISTER_32(ERU0_BASE + 0x1c)
#define EXOCON0			REGISTER_32(ERU0_BASE + 0x20)
#define EXOCON1			REGISTER_32(ERU0_BASE + 0x24)
#define EXOCON2			REGISTER_32(ERU0_BASE + 0x28)
#define EXOCON3			REGISTER_32(ERU0_BASE + 0x2c)

// PAU
#define AVAIL0			REGISTER_32(PAU_BASE + 0x40)
#define AVAIL1			REGISTER_32(PAU_BASE + 0x44)
#define AVAIL2			REGISTER_32(PAU_BASE + 0x48)
#define PRIVDIS0		REGISTER_32(PAU_BASE + 0x80)
#define PRIVDIS1		REGISTER_32(PAU_BASE + 0x84)
#define ROMSIZE			REGISTER_32(PAU_BASE + 0x400)
#define FLSIZE			REGISTER_32(PAU_BASE + 0x404)
#define RAM0SIZE		REGISTER_32(PAU_BASE + 0x410)

// WDT
#define WDT_ID			REGISTER_32(WDT_BASE + 0x00)
#define WDT_CTR			REGISTER_32(WDT_BASE + 0x04)
#define WDT_SRV			REGISTER_32(WDT_BASE + 0x08)
#define WDT_TIM			REGISTER_32(WDT_BASE + 0x0c)
#define WDT_WLB			REGISTER_32(WDT_BASE + 0x10)
#define WDT_WUB			REGISTER_32(WDT_BASE + 0x14)
#define WDT_WDTSTS		REGISTER_32(WDT_BASE + 0x18)
#define WDT_WDTCLR		REGISTER_32(WDT_BASE + 0x1c)

// RTC
#define RTC_ID			REGISTER_32(RTC_BASE + 0x00)
#define RTC_CTR			REGISTER_32(RTC_BASE + 0x04)
#define RTC_RAWSTAT		REGISTER_32(RTC_BASE + 0x08)
#define RTC_STSSR		REGISTER_32(RTC_BASE + 0x0c)
#define RTC_MSKSR		REGISTER_32(RTC_BASE + 0x10)
#define RTC_CLRSR		REGISTER_32(RTC_BASE + 0x14)
#define RTC_ATIM0		REGISTER_32(RTC_BASE + 0x18)
#define RTC_ATIM1		REGISTER_32(RTC_BASE + 0x1c)
#define RTC_TIM0		REGISTER_32(RTC_BASE + 0x20)
#define RTC_TIM1		REGISTER_32(RTC_BASE + 0x24)

// SCU (difficult to decipher in reference manual)
#define SCU_GCU_BASE 	(SCU_BASE + 0)
#define SCU_PCU_BASE 	(SCU_BASE + 0x200)
#define SCU_CCU_BASE 	(SCU_BASE + 0x300)
#define SCU_RCU_BASE 	(SCU_BASE + 0x400)
#define SCU_RTC_BASE 	(SCU_BASE + 0xa00)
#define SCU_ANACTRL_BASE (SCU_BASE + 0x1000)

#define SCU_ANAVDEL		REGISTER_32(SCU_PCU_BASE + 0x1050)
#define SCU_VDESR		REGISTER_32(SCU_PCU_BASE + 0)

#define SCU_CLKCR		REGISTER_32(SCU_CCU_BASE + 0x00)
#define SCU_PWRSVCR		REGISTER_32(SCU_CCU_BASE + 0x04)
#define SCU_CGATSTAT0	REGISTER_32(SCU_CCU_BASE + 0x08)
#define SCU_CGATSET0	REGISTER_32(SCU_CCU_BASE + 0x0c)
#define SCU_CGATCLR0	REGISTER_32(SCU_CCU_BASE + 0x10)
#define SCU_OSCCSR		REGISTER_32(SCU_CCU_BASE + 0x14)
#define SCU_ANAOFFSET	REGISTER_32(SCU_CCU_BASE + 0x106c)

#define SCU_RSTSTAT		REGISTER_32(SCU_RCU_BASE + 0x00)
#define SCU_RSTSET		REGISTER_32(SCU_RCU_BASE + 0x04)
#define SCU_RSTCLR		REGISTER_32(SCU_RCU_BASE + 0x08)
#define SCU_RSTCON		REGISTER_32(SCU_RCU_BASE + 0x0c)

#define SCU_ID			REGISTER_32(SCU_GCU_BASE + 0x08)
#define SCU_IDCHIP		REGISTER_32(SCU_GCU_BASE + 0x04)
#define SCU_DBGROMID	REGISTER_32(SCU_GCU_BASE + 0x00)
#define SCU_SSW0		REGISTER_32(SCU_GCU_BASE + 0x14)
#define SCU_CCUCON		REGISTER_32(SCU_GCU_BASE + 0x30)
#define SCU_SRRAW		REGISTER_32(SCU_GCU_BASE + 0x38)
#define SCU_SRMSK		REGISTER_32(SCU_GCU_BASE + 0x3c)
#define SCU_SRCLR		REGISTER_32(SCU_GCU_BASE + 0x40)
#define SCU_SRSET		REGISTER_32(SCU_GCU_BASE + 0x44)
#define SCU_PASSWD		REGISTER_32(SCU_GCU_BASE + 0x24)
#define SCU_MIRRSTS		REGISTER_32(SCU_GCU_BASE + 0x48)
#define SCU_PMTSR		REGISTER_32(SCU_GCU_BASE + 0x54)

// PRNG
#define PRNG_WORD		REGISTER_32(PRNG_BASE + 0x00)
#define PRNG_CHK		REGISTER_32(PRNG_BASE + 0x04)
#define PRNG_CTRL		REGISTER_32(PRNG_BASE + 0x0c)

// VADC0
#define VADC0_ID		REGISTER_32(VADC0_BASE + 0x008)
#define VADC0_CLC		REGISTER_32(VADC0_BASE + 0x000)
#define VADC0_OCS		REGISTER_32(VADC0_BASE + 0x028)
#define VADC0_GLOBCFG	REGISTER_32(VADC0_BASE + 0x080)
#define VADC0_BRSCTRL	REGISTER_32(VADC0_BASE + 0x200)
#define VADC0_BRSMR		REGISTER_32(VADC0_BASE + 0x204)
#define VADC0_BRSSEL0	REGISTER_32(VADC0_BASE + 0x180)
#define VADC0_BRSSEL1	REGISTER_32(VADC0_BASE + 0x184)
#define VADC0_BRSPND0	REGISTER_32(VADC0_BASE + 0x1c0)
#define VADC0_BRSPND1	REGISTER_32(VADC0_BASE + 0x1c4)
#define VADC0_GLOBICLASS0	REGISTER_32(VADC0_BASE + 0x0a0)
#define VADC0_GLOBICLASS1	REGISTER_32(VADC0_BASE + 0x0a4)
#define VADC0_GLOBRCR	REGISTER_32(VADC0_BASE + 0x280)
#define VADC0_GLOBRES	REGISTER_32(VADC0_BASE + 0x300)
#define VADC0_GLOBRESD	REGISTER_32(VADC0_BASE + 0x380)
#define VADC0_GLOBEFLAG	REGISTER_32(VADC0_BASE + 0x0e0)
#define VADC0_GLOBEVNP	REGISTER_32(VADC0_BASE + 0x140)

// SHS0
#define SHS0_ID			REGISTER_32(SHS0_BASE + 0x008)
#define SHS0_CFG		REGISTER_32(SHS0_BASE + 0x040)
#define SHS0_GNCTR00	REGISTER_32(SHS0_BASE + 0x180)
#define SHS0_GNCTR10	REGISTER_32(SHS0_BASE + 0x190)
#define SHS0_LOOP		REGISTER_32(SHS0_BASE + 0x050)

// TSE
#define	TSE_ANATSECTRL	REGISTER_32(TSE_BASE + 0x1024)
#define	TSE_ANATSEIH	REGISTER_32(TSE_BASE + 0x1030)
#define	TSE_ANATSEIL	REGISTER_32(TSE_BASE + 0x1034)
#define	TSE_ANATSEMON	REGISTER_32(TSE_BASE + 0x1040)

// CCU4
#define CCU4_GCTRL			REGISTER_32(CCU40_BASE + 0x0000)
#define CCU4_GSTAT			REGISTER_32(CCU40_BASE + 0x0004)
#define CCU4_GIDLS			REGISTER_32(CCU40_BASE + 0x0008)
#define CCU4_GIDLC			REGISTER_32(CCU40_BASE + 0x000c)
#define CCU4_GCSS			REGISTER_32(CCU40_BASE + 0x0010)
#define CCU4_GCSC			REGISTER_32(CCU40_BASE + 0x0014)
#define CCU4_GCST			REGISTER_32(CCU40_BASE + 0x0018)
#define CCU4_MIDR			REGISTER_32(CCU40_BASE + 0x0080)

// CCU4_SLICE0
#define CCU4_CC40INS		REGISTER_32(CCU40_BASE + 0x0100)
#define CCU4_CC40CMC		REGISTER_32(CCU40_BASE + 0x0104)
#define CCU4_CC40TST		REGISTER_32(CCU40_BASE + 0x0108)
#define CCU4_CC40TCSET		REGISTER_32(CCU40_BASE + 0x010c)
#define CCU4_CC40TCCLR		REGISTER_32(CCU40_BASE + 0x0110)
#define CCU4_CC40TC			REGISTER_32(CCU40_BASE + 0x0114)
#define CCU4_CC40PSL		REGISTER_32(CCU40_BASE + 0x0118)
#define CCU4_CC40DIT		REGISTER_32(CCU40_BASE + 0x011c)
#define CCU4_CC40DITS		REGISTER_32(CCU40_BASE + 0x0120)
#define CCU4_CC40PSC		REGISTER_32(CCU40_BASE + 0x0124)
#define CCU4_CC40FPC		REGISTER_32(CCU40_BASE + 0x0128)
#define CCU4_CC40FPCS		REGISTER_32(CCU40_BASE + 0x012c)
#define CCU4_CC40PR			REGISTER_32(CCU40_BASE + 0x0130)
#define CCU4_CC40PRS		REGISTER_32(CCU40_BASE + 0x0134)
#define CCU4_CC40CR			REGISTER_32(CCU40_BASE + 0x0138)
#define CCU4_CC40CRS		REGISTER_32(CCU40_BASE + 0x013c)
#define CCU4_CC40TIMER		REGISTER_32(CCU40_BASE + 0x0170)
#define CCU4_CC40C0V		REGISTER_32(CCU40_BASE + 0x0174)
#define CCU4_CC40C1V		REGISTER_32(CCU40_BASE + 0x0178)
#define CCU4_CC40C2V		REGISTER_32(CCU40_BASE + 0x017c)
#define CCU4_CC40C3V		REGISTER_32(CCU40_BASE + 0x0180)
#define CCU4_CC40INTS		REGISTER_32(CCU40_BASE + 0x01a0)
#define CCU4_CC40INTE		REGISTER_32(CCU40_BASE + 0x01a4)
#define CCU4_CC40SRS		REGISTER_32(CCU40_BASE + 0x01a8)
#define CCU4_CC40SWS		REGISTER_32(CCU40_BASE + 0x01ac)
#define CCU4_CC40SWR		REGISTER_32(CCU40_BASE + 0x01b0)
#define CCU4_CC40ECRD0 		REGISTER_32(CCU40_BASE + 0x01b8)
#define CCU4_CC40ECRD1 		REGISTER_32(CCU40_BASE + 0x01bc)

// CCU4_SLICE1
#define CCU4_CC41INS		REGISTER_32(CCU40_BASE + 0x0200)
#define CCU4_CC41CMC		REGISTER_32(CCU40_BASE + 0x0204)
#define CCU4_CC41TST		REGISTER_32(CCU40_BASE + 0x0208)
#define CCU4_CC41TCSET		REGISTER_32(CCU40_BASE + 0x020c)
#define CCU4_CC41TCCLR		REGISTER_32(CCU40_BASE + 0x0210)
#define CCU4_CC41TC			REGISTER_32(CCU40_BASE + 0x0214)
#define CCU4_CC41PSL		REGISTER_32(CCU40_BASE + 0x0218)
#define CCU4_CC41DIT		REGISTER_32(CCU40_BASE + 0x021c)
#define CCU4_CC41DITS		REGISTER_32(CCU40_BASE + 0x0220)
#define CCU4_CC41PSC		REGISTER_32(CCU40_BASE + 0x0224)
#define CCU4_CC41FPC		REGISTER_32(CCU40_BASE + 0x0228)
#define CCU4_CC41FPCS		REGISTER_32(CCU40_BASE + 0x022c)
#define CCU4_CC41PR			REGISTER_32(CCU40_BASE + 0x0230)
#define CCU4_CC41PRS		REGISTER_32(CCU40_BASE + 0x0234)
#define CCU4_CC41CR			REGISTER_32(CCU40_BASE + 0x0238)
#define CCU4_CC41CRS		REGISTER_32(CCU40_BASE + 0x023c)
#define CCU4_CC41TIMER		REGISTER_32(CCU40_BASE + 0x0270)
#define CCU4_CC41C0V		REGISTER_32(CCU40_BASE + 0x0274)
#define CCU4_CC41C1V		REGISTER_32(CCU40_BASE + 0x0278)
#define CCU4_CC41C2V		REGISTER_32(CCU40_BASE + 0x027c)
#define CCU4_CC41C3V		REGISTER_32(CCU40_BASE + 0x0280)
#define CCU4_CC41INTS		REGISTER_32(CCU40_BASE + 0x02a0)
#define CCU4_CC41INTE		REGISTER_32(CCU40_BASE + 0x02a4)
#define CCU4_CC41SRS		REGISTER_32(CCU40_BASE + 0x02a8)
#define CCU4_CC41SWS		REGISTER_32(CCU40_BASE + 0x02ac)
#define CCU4_CC41SWR		REGISTER_32(CCU40_BASE + 0x02b0)
#define CCU4_CC41ECRD0 		REGISTER_32(CCU40_BASE + 0x02b8)
#define CCU4_CC41ECRD1 		REGISTER_32(CCU40_BASE + 0x02bc)

// CCU4_SLICE2
#define CCU4_CC42INS		REGISTER_32(CCU40_BASE + 0x0300)
#define CCU4_CC42CMC		REGISTER_32(CCU40_BASE + 0x0304)
#define CCU4_CC42TST		REGISTER_32(CCU40_BASE + 0x0308)
#define CCU4_CC42TCSET		REGISTER_32(CCU40_BASE + 0x030c)
#define CCU4_CC42TCCLR		REGISTER_32(CCU40_BASE + 0x0310)
#define CCU4_CC42TC			REGISTER_32(CCU40_BASE + 0x0314)
#define CCU4_CC42PSL		REGISTER_32(CCU40_BASE + 0x0318)
#define CCU4_CC42DIT		REGISTER_32(CCU40_BASE + 0x031c)
#define CCU4_CC42DITS		REGISTER_32(CCU40_BASE + 0x0320)
#define CCU4_CC42PSC		REGISTER_32(CCU40_BASE + 0x0324)
#define CCU4_CC42FPC		REGISTER_32(CCU40_BASE + 0x0328)
#define CCU4_CC42FPCS		REGISTER_32(CCU40_BASE + 0x032c)
#define CCU4_CC42PR			REGISTER_32(CCU40_BASE + 0x0330)
#define CCU4_CC42PRS		REGISTER_32(CCU40_BASE + 0x0334)
#define CCU4_CC42CR			REGISTER_32(CCU40_BASE + 0x0338)
#define CCU4_CC42CRS		REGISTER_32(CCU40_BASE + 0x033c)
#define CCU4_CC42TIMER		REGISTER_32(CCU40_BASE + 0x0370)
#define CCU4_CC42C0V		REGISTER_32(CCU40_BASE + 0x0374)
#define CCU4_CC42C1V		REGISTER_32(CCU40_BASE + 0x0378)
#define CCU4_CC42C2V		REGISTER_32(CCU40_BASE + 0x037c)
#define CCU4_CC42C3V		REGISTER_32(CCU40_BASE + 0x0380)
#define CCU4_CC42INTS		REGISTER_32(CCU40_BASE + 0x03a0)
#define CCU4_CC42INTE		REGISTER_32(CCU40_BASE + 0x03a4)
#define CCU4_CC42SRS		REGISTER_32(CCU40_BASE + 0x03a8)
#define CCU4_CC42SWS		REGISTER_32(CCU40_BASE + 0x03ac)
#define CCU4_CC42SWR		REGISTER_32(CCU40_BASE + 0x03b0)
#define CCU4_CC42ECRD0 		REGISTER_32(CCU40_BASE + 0x03b8)
#define CCU4_CC42ECRD1 		REGISTER_32(CCU40_BASE + 0x03bc)

// CCU4_SLICE3
#define CCU4_CC43INS		REGISTER_32(CCU40_BASE + 0x0400)
#define CCU4_CC43CMC		REGISTER_32(CCU40_BASE + 0x0404)
#define CCU4_CC43TST		REGISTER_32(CCU40_BASE + 0x0408)
#define CCU4_CC43TCSET		REGISTER_32(CCU40_BASE + 0x040c)
#define CCU4_CC43TCCLR		REGISTER_32(CCU40_BASE + 0x0410)
#define CCU4_CC43TC			REGISTER_32(CCU40_BASE + 0x0414)
#define CCU4_CC43PSL		REGISTER_32(CCU40_BASE + 0x0418)
#define CCU4_CC43DIT		REGISTER_32(CCU40_BASE + 0x041c)
#define CCU4_CC43DITS		REGISTER_32(CCU40_BASE + 0x0420)
#define CCU4_CC43PSC		REGISTER_32(CCU40_BASE + 0x0424)
#define CCU4_CC43FPC		REGISTER_32(CCU40_BASE + 0x0428)
#define CCU4_CC43FPCS		REGISTER_32(CCU40_BASE + 0x042c)
#define CCU4_CC43PR			REGISTER_32(CCU40_BASE + 0x0430)
#define CCU4_CC43PRS		REGISTER_32(CCU40_BASE + 0x0434)
#define CCU4_CC43CR			REGISTER_32(CCU40_BASE + 0x0438)
#define CCU4_CC43CRS		REGISTER_32(CCU40_BASE + 0x043c)
#define CCU4_CC43TIMER		REGISTER_32(CCU40_BASE + 0x0470)
#define CCU4_CC43C0V		REGISTER_32(CCU40_BASE + 0x0474)
#define CCU4_CC43C1V		REGISTER_32(CCU40_BASE + 0x0478)
#define CCU4_CC43C2V		REGISTER_32(CCU40_BASE + 0x047c)
#define CCU4_CC43C3V		REGISTER_32(CCU40_BASE + 0x0480)
#define CCU4_CC43INTS		REGISTER_32(CCU40_BASE + 0x04a0)
#define CCU4_CC43INTE		REGISTER_32(CCU40_BASE + 0x04a4)
#define CCU4_CC43SRS		REGISTER_32(CCU40_BASE + 0x04a8)
#define CCU4_CC43SWS		REGISTER_32(CCU40_BASE + 0x04ac)
#define CCU4_CC43SWR		REGISTER_32(CCU40_BASE + 0x04b0)
#define CCU4_CC43ECRD0 		REGISTER_32(CCU40_BASE + 0x04b8)
#define CCU4_CC43ECRD1 		REGISTER_32(CCU40_BASE + 0x04bc)

// P0
#define P0_OUT				REGISTER_32(P0_BASE + 0x0000)
#define P0_OMR				REGISTER_32(P0_BASE + 0x0004)
#define P0_IOCR0			REGISTER_32(P0_BASE + 0x0010)
#define P0_IOCR4			REGISTER_32(P0_BASE + 0x0014)
#define P0_IOCR8			REGISTER_32(P0_BASE + 0x0018)
#define P0_IOCR12			REGISTER_32(P0_BASE + 0x001c)
#define P0_IN				REGISTER_32(P0_BASE + 0x0024)
#define P0_PHCR0			REGISTER_32(P0_BASE + 0x0040)
#define P0_PHCR1			REGISTER_32(P0_BASE + 0x0044)
#define P0_PDISC			REGISTER_32(P0_BASE + 0x0060)
#define P0_PPS				REGISTER_32(P0_BASE + 0x0070)
#define P0_HWSEL			REGISTER_32(P0_BASE + 0x0078)

// P1
#define P1_OUT				REGISTER_32(P1_BASE + 0x0000)
#define P1_OMR				REGISTER_32(P1_BASE + 0x0004)
#define P1_IOCR0			REGISTER_32(P1_BASE + 0x0010)
#define P1_IOCR4			REGISTER_32(P1_BASE + 0x0014)
#define P1_IOCR8			REGISTER_32(P1_BASE + 0x0018)
#define P1_IOCR12			REGISTER_32(P1_BASE + 0x001c)
#define P1_IN				REGISTER_32(P1_BASE + 0x0024)
#define P1_PHCR0			REGISTER_32(P1_BASE + 0x0040)
#define P1_PHCR1			REGISTER_32(P1_BASE + 0x0044)
#define P1_PDISC			REGISTER_32(P1_BASE + 0x0060)
#define P1_PPS				REGISTER_32(P1_BASE + 0x0070)
#define P1_HWSEL			REGISTER_32(P1_BASE + 0x0078)

// P2
#define P2_OUT				REGISTER_32(P2_BASE + 0x0000)
#define P2_OMR				REGISTER_32(P2_BASE + 0x0004)
#define P2_IOCR0			REGISTER_32(P2_BASE + 0x0010)
#define P2_IOCR4			REGISTER_32(P2_BASE + 0x0014)
#define P2_IOCR8			REGISTER_32(P2_BASE + 0x0018)
#define P2_IOCR12			REGISTER_32(P2_BASE + 0x001c)
#define P2_IN				REGISTER_32(P2_BASE + 0x0024)
#define P2_PHCR0			REGISTER_32(P2_BASE + 0x0040)
#define P2_PHCR1			REGISTER_32(P2_BASE + 0x0044)
#define P2_PDISC			REGISTER_32(P2_BASE + 0x0060)
#define P2_PPS				REGISTER_32(P2_BASE + 0x0070)
#define P2_HWSEL			REGISTER_32(P2_BASE + 0x0078)

#endif
