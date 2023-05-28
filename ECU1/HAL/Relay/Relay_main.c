#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Dio_int.h"
#include "Port_int.h"
#include "Relay_Int.h"
#include <util/delay.h>
extern const Port_ConfigType PORT_Config_Arr2[PORT_PINS_CONFIG_ARR2_SIZE];

int main()
{
	//Init
    Port_Init(PORT_Config_Arr2);

  while(1)
    {
           H_Relay_Void_WorkOn(Relay_2);
           _delay_ms(2000);
           H_Relay_Void_WorkOff(Relay_2);
           _delay_ms(2000);



    }
}