#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Dio_int.h"
#include "Port_int.h"  
#include "Buzzer_Int.h"
#include <util/delay.h>
extern const Port_ConfigType PORT_Config_Arr2[PORT_PINS_CONFIG_ARR2_SIZE];

int main()
{
	//Init
    Port_Init(PORT_Config_Arr2);
 while(1)
    {
           H_BUZZER_Void_TurnOn();
           _delay_ms(2000);
           H_BUZZER_Void_TurnOff();
           _delay_ms(2000);



    }
}