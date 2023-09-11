#include <stdint.h>

#include "00-LIB/STD_TYPES.h"
#include "00-LIB/BIT_Manipulation.h"
#include "00-LIB/Software_Delay.h"


#include"01-MCAL/00-RCC/RCC_interface.h"
#include"01-MCAL/01-PORT/PORT_interface.h"
#include"01-MCAL/02-GPIO/GPIO_interface.h"
#include"01-MCAL/03-EXTI/EXTI_interface.h"
#include"01-MCAL/06-USART/USART_interface.h"

#include"02-HAL/1-SevenSegment/SevenSeg_interface.h"

Seven_Segment_Object SSD_OBJ;

/* Functions Declaration*/
void System_Init (void);
void USART_Init(void);
void SSD_Init(void);

int main(void)
{
	/*1- System Initialization*/
	System_Init();

	/*2- PORT Initialization*/
	PORT_voidInit();

	/*3- UART Initialization*/
	USART_Init();

	/*4- SSD Initialization*/
	SSD_Init();



	//USART_voidSendByte(UART1,'f');
	//USART_voidSendByte(UART1,'l');
	//USART_voidSendByte(UART1,'o');

	u8 arr[16]="HelloEnterNumber";

	USART_voidSendString(UART1,arr);


	u8 DATA;
	USART_voidReceiveByteBlocking(UART1,&DATA);


//	USART_voidSendByte(UART1,DATA);

	if(DATA == '5')
	{
		GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN0,GPIO_PIN_HIGH);
	}
	if(DATA == 'r')
	{
		GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_PIN_HIGH);
	}

	/*convert char to int */
	u16 DATAINT=DATA-'0';

	/*Display number on SSD */
    SSD_Display_Number(SSD_OBJ,DATAINT);


    /* Loop forever */
	for(;;);


	/*_delay_ms(200);*/
}

void System_Init()
{
	/*configure System Clock*/
	RCC_voidSystemClockInit();

	/* Enable GPIOA clock */
	RCC_voidPeripheralClockEnable(RCC_AHB1,RCC_GPIOA);
	/* Enable GPIOB clock */
	RCC_voidPeripheralClockEnable(RCC_AHB1,RCC_GPIOB);

	/* Enable Selection line of MUX*/
	RCC_voidPeripheralClockEnable(RCC_APB2,RCC_SYSCFG);

	/* Enable USART clock */
	RCC_voidPeripheralClockEnable(RCC_APB2,RCC_USART1);
}


void USART_Init(void)
{
	USART_InitType UART_Config={.BaudRate=9600,
			.DataWidth=USART_8_Data_Bits,
			.StopBits=USART_1_Stop_Bit,
			.Parity_Enable=USART_Parity_DISABLE,
			.Parity_Selection=USART_Odd_Parity,
			.TransferDirection=USART_TX_RX,
			.Oversampling=OVER_SAMPLING_16,
	};

	USART_ClockInitTypeDef UART_CLOCK={
			.ClockOutput=0,
			.ClockPhase=0,
			.ClockPolarity=0,
	};

	USART_voidInit(&UART_Config,&UART_CLOCK,UART1);

}

void SSD_Init(void)
{
	SSD_OBJ.Enable_Pin  =  	   GPIO_PIN8;
	SSD_OBJ.Enable_port =      GPIO_PORTA;
	SSD_OBJ.Mode        =      Common_Cathode_Mode;
	SSD_OBJ.Port        =      GPIO_PORTA;
	SSD_OBJ.Start_Pin   =      GPIO_PIN0;
}
