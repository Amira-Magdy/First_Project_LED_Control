#include "GPIO_Int.h"
#include "SysCtrl_Int.h"
#include "GPT_Int.h"
#include "PORT_Int.h"
#include "IntCtrl_Int.h"
#include "Std_Types.h"

void LED_Implementation (void);
void Blinking_LED (u32 Ticks );

int main(void)
{	
	
	SysCtrl_MicrocontrollerInit();
	IntCrtl_Init();
	PORT_Init();
	GPT_Init();
	
	while(1)
	{
		Blinking_LED (16000000);//16Mhz - > 1sec
	}
	return 0;
}

void LED_Implementation (void)
{
	GPIO_FlipChannel( PF2 );
}
void Blinking_LED (u32 Ticks )
{
	GPT_EnableNotification(T0);
	GPT_Notification_T0(LED_Implementation);
	GPT_StartTimer(T0 , Ticks);
}