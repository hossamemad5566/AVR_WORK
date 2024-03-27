/******************************************************************
 * @name : Hossam Emad 
 * @date : 1/3/2023
 * @SWC  : DIO 
 * @vesrion: V1.0
 * ****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

/*MCAL layer*/
#include "DIO_interface.h"
#include "seg_interface.h"

int main (void)
{

    DIO_voidInit();
    Seg_voidInint();
    seg_u8DipLocTime(SEG_LOC_2,8,2000);

    while(1)
    {
       

    seg_u8Disp4digit(2024);


    
        
    }
    return 0;
}
