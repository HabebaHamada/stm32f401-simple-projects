/*********************************************************/
/* Author  :              H    H                         */
/* Date    :  21 JULY 2023                               */
/* Version :  V1.0                                       */
/*********************************************************/
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H


#define TIM1 0
#define TIM2 1
#define TIM3 2
#define TIM4 3

#define CHANNEL1 0
#define CHANNEL2 1
#define CHANNEL3 2
#define CHANNEL4 3

typedef enum
{  
   UPCOUNTING_MODE,
   DOWNCOUNTING_MODE,
   CENTER_ALIGNED_MODE,
}Timer_Mode;


typedef enum
{  
   No_prescaler,
   Prescaler_By_2,
   Prescaler_By_4,
   Prescaler_By_8,
}InputCapture_prescaler;

typedef enum
{  
   FallingEdge,
   RisingEdge,
}InputCapture_polarity;

#define OVERFLOW_VALUE (0xFFFF)
#define PRESCALAR        1     // Tick Time is 1 Micro Second


/*---------------------------------------------------------------------*/
/*******
Function Description: This Function Initialize TIMER1 2 3 4
parameters: Copy_u8TimerNum       : Selects Which Timer To Be Used
			Copy_u8TimerMode	  : Selects Which Mode The Timer Will Operate On
			Copy_u16TimerPreScaler: Specifies The Value Of Prescaler
			Copy_u16TimerARRValue : Specifies The Value Of ARR_Register The Timer Will Count Until It
return: void
*/
void Timer_voidInit(u8 Copy_u8TimerNum, Timer_Mode Copy_u8TimerMode, u16 Copy_u16TimerPreScaler, u16 Copy_u16TimerARRValue);


/*******
	Function Description: This Is A Callback Function Executes a Specific Function After Timer Interrupt
	parameter: Copy_u8TimerNum: Selects Which Timer To Be Used
			   Ptr2Func: Pointer To Function Takes The Address Of The Upper Layer Function
	return: void
*/
void Timer_voidSetCallBack(u8 Copy_u8TimerNum, void (*PTR2FUNC)(void));


/*******
	Function Description: This Function Initialize PWM Mode
	parameter: Copy_u8TimerNum : Selects Which Timer To Be Used
			   opy_u8ChannelNum: Selects Which Channel To Operate
	return: void
*/
void Timer_voidEnablePWM(u8 Copy_u8TimerNum, u8 Copy_u8ChannelNum);


/*******
	Function Description: This Function Initialize PWM Mode
	parameter: Copy_u8TimerNum  : Selects Which Timer To Be Used
			   opy_u8ChannelNum : Selects Which Channel To Operate
			   Copy_u16DutyCycle: Set The Duty Cycle Of PWM Signal
	return: none
*/
void Timer_voidSelectChannel(u8 Copy_u8TimerNum, u8 Copy_u8ChannelNum,u16 Copy_u16DutyCycle);

/*******
	Function Description: This Function Delays The Controller For Microseconds
	parameter: Copy_Time_US  : Number Of Microseconds Required For Delay
	return: none
*/
void Timer_Delay_us(u16 Copy_Time_US);

/*******
	Function Description: This Function Delays The Controller For Milliseconds
	parameter: Copy_Time_MS  : Number Of Milliseconds Required For Delay
	return: none
*/
void Timer_Delay_ms(u16 Copy_Time_MS);

/*******
	Function Description        : This Function Initialize The Input Capture Unit
	parameter: Copy_u8TimerNum  : Selects Which Timer to Be Used
	           Copy_u8ChannelNum: Selects Which Channel to Be Used
	return: none
*/
void Timer_EnableInputCapture(u8 Copy_u8TimerNum, u8 Copy_u8ChannelNum);

/*******
	Function Description              : This Function Gets The CCR1 Value
	parameter: Copy_u8TimerNum        : Selects Which Timer To Be Used
	           Copy_u8ChannelNum      : Selects Which Channel to Be Used
	return:    Local_u16Counter_Valued: The CCR1 Value
*/
u16 Timer_GetCCRValue(u8 Copy_u8TimerNum, u8 Copy_u8ChannelNum);

/*******
	Function Description              : This Function Sets InputCapture Uint Polarity
	parameter: Copy_u8TimerNum        : Selects Which Timer To Be Used
			   Copy_u8Polarity        : Selects The Desired Polarity
	           Copy_u8ChannelNum      : Selects Which Channel to Be Used
	return:    void
*/
void Timer_SetInputCapturePolarity(u8 Copy_u8TimerNum, InputCapture_polarity Copy_u8Polarity, u8 Copy_u8ChannelNum);

/*******
	Function Description              : This Function Clears Counter Value
	parameter: Copy_u8TimerNum        : Selects Which Timer To Be Used
	return:    void
*/
void Timer_ClearCounter(u8 Copy_u8TimerNum);
#endif
  
