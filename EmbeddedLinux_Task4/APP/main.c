#include "../MCAL/PORT/MPort_Interface.h"
#include "../MCAL/DIO/DIO.h"


int main(void)
{
    PORT_voidPortInit();
    while(1)
    {	     
    DIO_enuSetPinValue(DIO_enuPort_A,DIO_enuPin_0,DIO_enuHigh);	
    }
    return 0;
}
