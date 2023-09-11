/*********************************************************/
/* Author  :              H    H                         */
/* Date    :  21 JULY 2023                               */
/* Version :  V1.0                                       */
/*********************************************************/
#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H


#define TIMER1_BASE_ADDRESS      (u32)(0x40010000)
#define TIMER2_BASE_ADDRESS      (u32)(0x40000000)
#define TIMER3_BASE_ADDRESS      (u32)(0x40000400)
#define TIMER4_BASE_ADDRESS      (u32)(0x40000800)


typedef struct{

	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
	volatile u32 RCR;
	volatile u32 CCR1;
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;
	volatile u32 BDTR;
	volatile u32 DCR;
	volatile u32 DMAR;

}TIM1_t;

#define TIMER1		((volatile TIM1_t*)TIMER1_BASE_ADDRESS)


/***********   REGISTER ADDRESSES FOR TIM2     ***********************/

typedef struct{

	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;

	volatile u32 RESERVED;   //Empty

	volatile u32 CCR1;
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;

	volatile u32 RESERVED1;   //Empty

	volatile u32 DCR;
	volatile u32 DMAR;

}TIMER_t;


#define TIMER2		((volatile TIMER_t*)TIMER2_BASE_ADDRESS)
#define TIMER3		((volatile TIMER_t*)TIMER3_BASE_ADDRESS)
#define TIMER4		((volatile TIMER_t*)TIMER4_BASE_ADDRESS)

typedef enum
{
	CEN,
	UDIS,
	URS	,
	OPM	,
	DIR	,
	CMS0,
	CMS1,
	ARPE,
	CKD0,
	CKD1,

}CR1_PINS_t;


typedef enum
{
	CC1S0,
	CC1S1,
	IC1PSC0,
	IC1PSC1,
	IC1F0,
	IC1F1,
	IC1F2,
	IC1F3,
	CC2S0,
	CC2S1,
	IC2PSC0,
	IC2PSC1,
	IC2F0,
	IC2F1,
	IC2F2,
	IC2F3,

}CCMR1_PINS_t;

typedef enum
{
	CC3S0,
	CC3S1,
	IC3PSC0,
	IC3PSC1,
	IC3F0,
	IC3F1,
	IC3F2,
	IC3F3,
	CC4S0,
	CC4S1,
	IC4PSC0,
	IC4PSC1,
	IC4F0,
	IC4F1,
	IC4F2,
	IC4F3,

}CCMR2_PINS_t;

typedef enum
{
	UIE,
	CC1IE,
	CC2IE,
	CC3IE,
	CC4IE,

}DIER_PINS_t;
typedef enum
{
	CC1E,
	CC1P,
	CC1NP=3,
	CC2E,
	CC2P,
	CC2NP=7,
	CC3E,
	CC3P,
	CC3NP=11,
	CC4E,
	CC4P,
	CC4NP=15,

}CCER_PINS_t;

typedef enum
{
	UG,
}EGR_PINS_t;


/* Delays Configurations*/
//#define OVERFLOW_VALUE (0xFFFF-1)
#define PRESCALAR        1  // Tick Time is 1 Micro Second
#define ONE_MILLISECOND 1000



 

#endif
