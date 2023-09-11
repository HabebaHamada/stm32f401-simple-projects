

#include <stdint.h>


#include"STD_TYPES.h"
#include"BIT_Manipulation.h"

#include"RCC_interface.h"
#include"GPIO_interface.h"
#include"PORT_interface.h"
#include"USART_interface.h"

#include"LED_interface.h"


int main(void)
{

	  RCC_voidSysClkInit();
	  RCC_voidEnablePeripheralClk(RCC_AHB1,GPIOA);
	  RCC_voidEnablePeripheralClk(RCC_AHB1,GPIOB);

	  RCC_voidEnablePeripheralClk(RCC_APB2,USART1);

	  PORT_voidInit();
	  USART1_voidInit();

	 //   LED_Object LED1={Source_Connection_type,GPIO_PORTA,GPIO_PIN0};
	   // LED_Object LED2={Source_Connection_type,GPIO_PORTA,GPIO_PIN2};



	  u8 DATA;
		   USART1_voidSynchReceiveData(&DATA);

	    USART1_voidSendData('1');
	    USART1_voidSendData('4');
	   /* USART1_voidSendData('3');
	    USART1_voidSendData('4');*/

	    if(DATA == '5')
	    {
	    	GPIO_SetPinValue(GPIO_PIN0,GPIO_PORTB,GPIO_PIN_HIGH);
	    }
	    if(DATA == 'r')
	    {
	    	GPIO_SetPinValue(GPIO_PIN1,GPIO_PORTB,GPIO_PIN_HIGH);
	    }




		while(1)
		{

		}
}
