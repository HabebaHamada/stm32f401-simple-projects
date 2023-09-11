/*********************************************************/
/* Author  :              H    H                         */
/* Date    :  21 JULY 2023                               */
/* Version :  V1.0                                       */
/*********************************************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_Manipulation.h"

#include "TIMER_interface.h"
#include "TIMER_config.h"
#include "TIMER_private.h"


volatile TIMER_t* TIMERx;
static void(*Timer1_CallBack_PTR)(void);
static void(*Timer2_CallBack_PTR)(void);
static void(*Timer3_CallBack_PTR)(void);
static void(*Timer4_CallBack_PTR)(void);

void Timer_voidInit(u8 Copy_u8TimerNum, Timer_Mode Copy_u8TimerMode, u16 Copy_u16TimerPreScaler, u16 Copy_u16TimerARRValue)
{
	/* Selecting Which Timer Will Operate*/
	if(Copy_u8TimerNum == TIM1)
	{
		/* Select Timer 1 */
		//TIMERx = (volatile TIM1_t*) TIMER1_BASE_ADDRESS;
		
		/* Select Timer Mode */
		if(Copy_u8TimerMode == UPCOUNTING_MODE)
		{
			/* SET UPCOUNTING_MODE */
			CLEAR_BIT(TIMER1->CR1, DIR);
			
			/* SET PRESCALER */
			TIMER1->PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMER1->ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMER1->CR1, CEN);
		}
	    else if(Copy_u8TimerMode ==  DOWNCOUNTING_MODE)
		{
			/* SET DOWNCOUNTING_MODE */
			SET_BIT(TIMER1->CR1, DIR);
			
			/* SET PRESCALER */
			TIMER1->PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMER1->ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMER1->CR1, CEN);
		}
	    else if(Copy_u8TimerMode ==  CENTER_ALIGNED_MODE)
		{
			
		}
	}
	else if(Copy_u8TimerNum == TIM2)
	{
		/* Select Timer 2*/
		TIMERx = (volatile TIMER_t*) TIMER2_BASE_ADDRESS;
		
		/* Select Timer Mode */
		if(Copy_u8TimerMode == UPCOUNTING_MODE)
		{
			/* SET UPCOUNTING_MODE */
			CLEAR_BIT(TIMERx->CR1, DIR);
			
			/* SET PRESCALER */
			TIMERx->PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMERx->ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMERx->CR1, CEN);
		}
		else if(Copy_u8TimerMode ==  DOWNCOUNTING_MODE)
		{
			/* SET DOWNCOUNTING_MODE */
			SET_BIT(TIMERx->CR1, DIR);
			
			/* SET PRESCALER */
			TIMERx->PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMERx->ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMERx->CR1, CEN);
		}
		else if(Copy_u8TimerMode ==  CENTER_ALIGNED_MODE)
		{
			
		}
	}
	else if(Copy_u8TimerNum == TIM3)
	{
		/* Select Timer 3*/
		TIMERx = (volatile TIMER_t*)TIMER3_BASE_ADDRESS;
		
		/* Select Timer Mode */
		if(Copy_u8TimerMode == UPCOUNTING_MODE)
		{
			/* SET UPCOUNTING_MODE */
			CLEAR_BIT(TIMERx->CR1, DIR);
			
			/* SET PRESCALER */
			TIMERx->PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMERx->ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMERx->CR1, CEN);
		}
		else if(Copy_u8TimerMode ==  DOWNCOUNTING_MODE)
		{
			/* SET DOWNCOUNTING_MODE */
			SET_BIT(TIMERx->CR1, DIR);
			
			/* SET PRESCALER */
			TIMERx->PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMERx->ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMERx->CR1, CEN);
		}
		else if(Copy_u8TimerMode ==  CENTER_ALIGNED_MODE)
		{
			
		}
	}
	else if(Copy_u8TimerNum == TIM4)
	{
		/* Select Timer 4*/
		TIMERx = (volatile TIMER_t*)TIMER4_BASE_ADDRESS;
		
		/* Select Timer Mode */
		if(Copy_u8TimerMode == UPCOUNTING_MODE)
		{
			/* SET UPCOUNTING_MODE */
			CLEAR_BIT(TIMERx->CR1, DIR);
			
			/* SET PRESCALER */
			TIMERx->PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMERx->ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMERx->CR1, CEN);
		}
		else if(Copy_u8TimerMode ==  DOWNCOUNTING_MODE)
		{
			/* SET DOWNCOUNTING_MODE */
			SET_BIT(TIMERx->CR1, DIR);
			
			/* SET PRESCALER */
			TIMERx->PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMERx->ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMERx->CR1, CEN);
		}
		else if(Copy_u8TimerMode ==  CENTER_ALIGNED_MODE)
		{
			
		}
	}
	
}

void Timer_voidSetCallBack(u8 Copy_u8TimerNum, void (*PTR2FUNC)(void))
{
	if(Copy_u8TimerNum == TIM1)
	{
		Timer1_CallBack_PTR = PTR2FUNC;
	}
	else if(Copy_u8TimerNum == TIM2)
	{
		Timer2_CallBack_PTR = PTR2FUNC;
	}
	else if(Copy_u8TimerNum == TIM3)
	{
		Timer3_CallBack_PTR = PTR2FUNC;
	}
	else if(Copy_u8TimerNum == TIM4)
	{
		Timer4_CallBack_PTR = PTR2FUNC;
	}		
}


void Timer_Delay_us(u16 Copy_Time_US)
{
	 /*Initialize Timer 4*/
	Timer_voidInit(TIM4, UPCOUNTING_MODE, PRESCALAR, OVERFLOW_VALUE);

	/* Re-initialize the counter */
	SET_BIT(TIMER4->EGR, 0);

	while(TIMER4->CNT < Copy_Time_US)
	{
		/* Loop Until Reaching The Required Count(Time) */
	}
}

void Timer_Delay_ms(u16 Copy_Time_MS)
{
	for(u16 Local_Iterator =0; Local_Iterator < Copy_Time_MS; Local_Iterator++)
	{
		/* Delay In Milliseconds*/
		Timer_Delay_us(ONE_MILLISECOND);
	}
}

void Timer_EnableInputCapture(u8 Copy_u8TimerNum, u8 Copy_u8ChannelNum)
{
	if(Copy_u8TimerNum == TIM1)
	{
		/* Select Timer 1 */
		//TIMERx = (volatile TIM1_t*) TIMER1_BASE_ADDRESS;
		if(Copy_u8ChannelNum == CHANNEL2)
		{
			/* Write CC2S Bites */
			SET_BIT(TIMER1->CCMR1, 8);
			CLEAR_BIT(TIMER1->CCMR1, 9);

			/*IC2F Bites*/
			SET_BIT(TIMER1->CCMR1, 12);
			SET_BIT(TIMER1->CCMR1, 13);
			CLEAR_BIT(TIMER1->CCMR1, 14);
			CLEAR_BIT(TIMER1->CCMR1, 15);

			/* Rising Edge*/
			CLEAR_BIT(TIMER1->CCER, 5);

			/* Enable Capture The Value From Counter */
			SET_BIT(TIMER1->CCER, 4);

			/* Enable Interrupt */
			SET_BIT(TIMER1->DIER, 2);
		}
	}
	else if(Copy_u8TimerNum == TIM2)
	{
		/* Select Timer  2*/
		TIMERx = (volatile TIMER_t*) TIMER2_BASE_ADDRESS;
	}
	else if(Copy_u8TimerNum == TIM3)
	{
		/* Select Timer 3 */
		TIMERx = (volatile TIMER_t*) TIMER3_BASE_ADDRESS;
	}
	else if(Copy_u8TimerNum == TIM4)
	{
		/* Select Timer 4 */
		TIMERx = (volatile TIMER_t*) TIMER4_BASE_ADDRESS;
	}
	
	if(Copy_u8ChannelNum == CHANNEL1)
	{
		/* Disable Capture The Value From Counter */
		CLEAR_BIT(TIMERx->CCER, CC1E);
		
		/* Write CC1S Bites */
		SET_BIT(TIMERx->CCMR1, CC1S0);
		CLEAR_BIT(TIMERx->CCMR1, CC1S1);
		
		/*IC1F Bites to configure sampling freq*/
		SET_BIT(TIMERx->CCMR1, IC1F0);
		SET_BIT(TIMERx->CCMR1, IC1F1);
		CLEAR_BIT(TIMERx->CCMR1, IC1F2);
		CLEAR_BIT(TIMERx->CCMR1, IC1F3);
		
		/* Rising Edge*/
		CLEAR_BIT(TIMERx->CCER, CC1P);
		
		/*prescaler configuration*/
		TIMERx->CCMR1|=(No_prescaler>>IC1PSC0);

		/* Enable Capture The Value From Counter */
		SET_BIT(TIMERx->CCER, CC1E);
		
		/* Enable Capture The Value From Counter */
		SET_BIT(TIMERx->DIER, CC1IE);
	}
	else if(Copy_u8ChannelNum == CHANNEL2)
	{
		/* Disable Capture The Value From Counter */
		CLEAR_BIT(TIMERx->CCER, CC2E);
		
		/* Write CC2S Bites */
		SET_BIT(TIMERx->CCMR1,   CC2S0);
		CLEAR_BIT(TIMERx->CCMR1, CC2S1);
		
	    /*IC2F Bites to configure sampling freq*/
		SET_BIT(TIMERx->CCMR1, IC2F0);
		SET_BIT(TIMERx->CCMR1, IC2F1);
		CLEAR_BIT(TIMERx->CCMR1, IC2F2);
		CLEAR_BIT(TIMERx->CCMR1, IC2F3);
		
		/* Rising Edge*/
		CLEAR_BIT(TIMERx->CCER, CC1P);
		
		/*prescaler configuration*/
		TIMERx->CCMR1|=(No_prescaler>>IC2PSC0);

		/* Enable Capture The Value From Counter */
		SET_BIT(TIMERx->CCER, CC2E);
		
		/* Enable Interrupt */
		SET_BIT(TIMERx->DIER, CC2IE);
	}
	else if(Copy_u8ChannelNum == CHANNEL3)
	{
		/* Disable Capture The Value From Counter */
		CLEAR_BIT(TIMERx->CCER, CC3E);
		
		/* Write CC3S Bites */
		SET_BIT(TIMERx->CCMR2, CC3S0);
		CLEAR_BIT(TIMERx->CCMR2, CC3S1);
		
		/*IC3F Bites*/
		SET_BIT(TIMERx->CCMR2, IC3F0);
		SET_BIT(TIMERx->CCMR2, IC3F1);
		CLEAR_BIT(TIMERx->CCMR2, IC3F2);
		CLEAR_BIT(TIMERx->CCMR2, IC3F3);
		
		/* Rising Edge*/
		CLEAR_BIT(TIMERx->CCER, CC3P);
		
		/*prescaler configuration*/
		TIMERx->CCMR1|=(No_prescaler>>IC3PSC0);

		/* Enable Capture The Value From Counter */
		SET_BIT(TIMERx->CCER, CC3E);
		
		/* Enable Capture The Value From Counter */
		SET_BIT(TIMERx->DIER, CC3IE);
	}
	else if(Copy_u8ChannelNum == CHANNEL4)
	{
		/* Disable Capture The Value From Counter */
		CLEAR_BIT(TIMERx->CCER, CC4E);
		
		/* Write CC4S Bites */
		SET_BIT(TIMERx->CCMR2, CC4S0);
		CLEAR_BIT(TIMERx->CCMR2, CC4S1);
		
		/*IC4F Bites*/
		SET_BIT(TIMERx->CCMR2, IC4F0);
		SET_BIT(TIMERx->CCMR2, IC4F1);
		CLEAR_BIT(TIMERx->CCMR2, IC4F2);
		CLEAR_BIT(TIMERx->CCMR2, IC4F3);
		
		/* Rising Edge*/
		CLEAR_BIT(TIMERx->CCER, CC4P);
		
		
		/*prescaler configuration*/
		TIMERx->CCMR1|=(No_prescaler>>IC4PSC0);

		/* Enable Capture The Value From Counter */
		SET_BIT(TIMERx->CCER, CC4E);
		
		/* Enable Interrupt */
		SET_BIT(TIMERx->DIER, CC4IE);
	}
}

u16 Timer_GetCCRValue(u8 Copy_u8TimerNum, u8 Copy_u8ChannelNum)
{
	u16 Local_u16Counter_Value = 0;
		
  if(Copy_u8TimerNum == TIM1)
	{
		/* Select Timer 1 */
		//TIMERx = (volatile TIM1_t*) TIMER1_BASE_ADDRESS;

	  if(Copy_u8ChannelNum == CHANNEL1)
	  {
		  Local_u16Counter_Value =	TIMER1->CCR1;
	  }
	  else if(Copy_u8ChannelNum == CHANNEL2)
	  {
		  Local_u16Counter_Value =	TIMER1->CCR2;
	  }
	  else if(Copy_u8ChannelNum == CHANNEL3)
	  {
		  Local_u16Counter_Value =	TIMER1->CCR3;
	  }
	  else if(Copy_u8ChannelNum == CHANNEL4)
	  {
		  Local_u16Counter_Value =	TIMER1->CCR4;
	  }

	}
	else if(Copy_u8TimerNum == TIM2)
	{
		/* Select Timer  2*/
		TIMERx = (volatile TIMER_t*) TIMER2_BASE_ADDRESS;
	}
	else if(Copy_u8TimerNum == TIM3)
	{
		/* Select Timer 3 */
		TIMERx = (volatile TIMER_t*) TIMER3_BASE_ADDRESS;
	}
	else if(Copy_u8TimerNum == TIM4)
	{
		/* Select Timer 4 */
		TIMERx = (volatile TIMER_t*) TIMER4_BASE_ADDRESS;
	}
		
    if(Copy_u8ChannelNum == CHANNEL1)
	{
		Local_u16Counter_Value =	TIMERx->CCR1;
	}
	else if(Copy_u8ChannelNum == CHANNEL2)
	{
		Local_u16Counter_Value =	TIMERx->CCR2;
	}
	else if(Copy_u8ChannelNum == CHANNEL3)
	{
		Local_u16Counter_Value =	TIMERx->CCR3;
	}
	else if(Copy_u8ChannelNum == CHANNEL4)
	{
		Local_u16Counter_Value =	TIMERx->CCR4;
	}
		
		return Local_u16Counter_Value;
}

void Timer_SetInputCapturePolarity(u8 Copy_u8TimerNum, InputCapture_polarity Copy_u8Polarity, u8 Copy_u8ChannelNum)
{
		
	if(Copy_u8TimerNum == TIM1)
	{
		/* Select Timer 1 */
		//TIMERx = (volatile TIM1_t*) TIMER1_BASE_ADDRESS;
		if(Copy_u8ChannelNum == CHANNEL2)
		{
			if(Copy_u8Polarity == RisingEdge)
			{
				CLEAR_BIT(TIMER1->CCER, 5);
			}
			else if(Copy_u8Polarity == FallingEdge)
			{
				SET_BIT(TIMER1->CCER, 5);
			}
		}
	}
	else if(Copy_u8TimerNum == TIM2)
	{
		/* Select Timer  2*/
		TIMERx = (volatile TIMER_t*) TIMER2_BASE_ADDRESS;
	}
	else if(Copy_u8TimerNum == TIM3)
	{
		/* Select Timer 3 */
		TIMERx = (volatile TIMER_t*) TIMER3_BASE_ADDRESS;
	}
	else if(Copy_u8TimerNum == TIM4)
	{
		/* Select Timer 4 */
		TIMERx = (volatile TIMER_t*) TIMER4_BASE_ADDRESS;
	}	
		
	if(Copy_u8ChannelNum == CHANNEL1)
	{
		if(Copy_u8Polarity == RisingEdge)
		{
			CLEAR_BIT(TIMERx->CCER, CC1P);
		}
		else if(Copy_u8Polarity == FallingEdge)
		{
			SET_BIT(TIMERx->CCER, CC1P);
		}
	}
	else if(Copy_u8ChannelNum == CHANNEL2)
	{
		if(Copy_u8Polarity == RisingEdge)
		{
			CLEAR_BIT(TIMERx->CCER, CC2P);
		}
		else if(Copy_u8Polarity == FallingEdge)
		{
			SET_BIT(TIMERx->CCER, CC2P);
		}
	}
	else if(Copy_u8ChannelNum == CHANNEL3)
	{
		if(Copy_u8Polarity == RisingEdge)
		{
			CLEAR_BIT(TIMERx->CCER, CC3P);
		}
		else if(Copy_u8Polarity == FallingEdge)
		{
			SET_BIT(TIMERx->CCER, CC3P);
		}
	}
	else if(Copy_u8ChannelNum == CHANNEL4)
	{
		if(Copy_u8Polarity == RisingEdge)
		{
			CLEAR_BIT(TIMERx->CCER, CC4P);
		}
		else if(Copy_u8Polarity == FallingEdge)
		{
			SET_BIT(TIMERx->CCER, CC4P);
		}
	}

		
}
void Timer_ClearCounter(u8 Copy_u8TimerNum)
{
	if(Copy_u8TimerNum == TIM1)
		{
			/* Select Timer 1 */
			TIMER1->CNT=0;
		}
	else if(Copy_u8TimerNum == TIM2)
		{
			/* Select Timer 2 */
			TIMER2->CNT=0;
		}
	else if(Copy_u8TimerNum == TIM3)
		{
			/* Select Timer 3 */
			TIMER3->CNT=0;
		}
	else if(Copy_u8TimerNum == TIM4)
		{
			/* Select Timer 4 */
			TIMER4->CNT=0;
		}
}


void TIM1_CC_IRQHandler(void)
{
	Timer1_CallBack_PTR();
}
void TIM2_IRQHandler(void)
{
	Timer2_CallBack_PTR();
}
void TIM3_IRQHandler(void)
{
	Timer3_CallBack_PTR();
}
void TIM4_IRQHandler(void)
{
	Timer4_CallBack_PTR();
}	
