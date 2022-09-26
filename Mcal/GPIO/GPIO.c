/*
 * FILE NAME:	GPIO.c
 * AUTHOR: Amira_Magdy_Mohamed
 * DATE:	20/9/2022
 * COMMENT:	contains functions implemntations
 */


/*  Includes  */

#include "Bit_Math.h"
#include "Std_Types.h"
#include "GPIO_Int.h"
#include "GPIO_Conf.h"
#include "Mcu_Hw.h"
#include "GPIO_Pri.h"

/************************************
    GLOBAL FUNCTIONS
************************************/

/******************************************************************************
* Description: Sets Output Port value as desired 
*******************************************************************************/
void GPIO_WritePort (GPIO_PortType PortId, GPIO_PortLevelType Level)
{
	GPIODIR(PortId) = (GPIO_PortLevelType)PORT_OUTPUT; 
	GPIODATA(PortId).R = Level;
}


/******************************************************************************
* Description: Sets a specific Output Pin value as desired                                    
*******************************************************************************/
void GPIO_WriteChannel (GPIO_ChannelType ChannelId, GPIO_LevelType Level)
{
	GPIO_PortType PORTi = (u8) (ChannelId / 10);
	GPIO_PinNo	  PINi	= ChannelId % 10;
	
	SET_BIT(GPIODIR(PORTi), ChannelId);
	GPIODATA(PORTi).R |= Level << PINi;
}


/******************************************************************************
* Description: Receives Input from a specific port                                    
*******************************************************************************/
GPIO_PortLevelType GPIO_ReadPort (GPIO_PortType PortId)
{
	return GPIODATA(PortId).R;
}


/******************************************************************************
* Description: Receives Input from a specific pin                                   
*******************************************************************************/
GPIO_LevelType GPIO_ReadChannel (GPIO_ChannelType ChannelId)
{
	GPIO_PortType PORTi = (u8) (ChannelId / 10);
	GPIO_PinNo	  PINi	= ChannelId % 10;
	
	return ( GET_BIT(GPIODATA(PORTi).R ,PINi) );
}


/******************************************************************************
* Description: Toggles pin value
*******************************************************************************/
GPIO_LevelType GPIO_FlipChannel (GPIO_ChannelType ChannelId)
{
	GPIO_PortType PORTi = (u8) (ChannelId / 10);
	GPIO_PinNo	  PINi	= ChannelId % 10;
		
	return TOG_BIT(GPIODATA(PORTi).R ,PINi) ;
}
