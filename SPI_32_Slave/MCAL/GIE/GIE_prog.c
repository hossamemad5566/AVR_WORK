/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : GIE
 * @about :
****************************************/
#include "GIE_interface.h"
#include "GIE_Private.h"

#include "../../LIB/BitMath.h"
#include "../../LIB/STD.h"

void GIE_voidEnable(void)
{
    SET_BIT(GIE_SREG,7);
}
void GIE_voidDisble(void)
{
    CLR_BIT(GIE_SREG,7);
}

