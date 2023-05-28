/*
 * EXTI_INT_cfg.h
 *
 *  Created on: Feb 24, 2023
 *      Author: ahmed57
 */



#ifndef EXTI_INT_CFG_H_
#define EXTI_INT_CFG_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "EXTI_INT_types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define EXTI_INT_ArrConfig_Size				1

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct{

	EXTI_ID					INT_ID;
	EXTI_SenseType_t		INT_SENSE;

}EXTI_CONFIG_t;

EXTI_CONFIG_t	EXTI_INT_ArrConfig[EXTI_INT_ArrConfig_Size];

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE:
 *********************************************************************************************************************/
#endif /* EXTI_INT_CFG_H_ */
