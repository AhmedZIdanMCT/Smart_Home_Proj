/*
 * EXTI_INT_int.h
 *
 *  Created on: Feb 24, 2023
 *      Author: ahmed57
 */
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/

#ifndef EXTI_INT_INT_H_
#define EXTI_INT_INT_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include <avr/interrupt.h>
#include "STD_TYPES.h"
#include "EXTI_INT_cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void M_vEXTI_INT_Enable(EXTI_CONFIG_t	EXTI_Arr[]);
void M_vEXTI_INT_Disable(EXTI_CONFIG_t	EXTI_INT);
void M_vEXTI_SetCallBack(void (*Ptrf)(void), EXTI_ID  ID);



#endif /* EXTI_INT_EXTI_INT_INT_H_ */

/**********************************************************************************************************************
 *  END OF FILE:
 *********************************************************************************************************************/



