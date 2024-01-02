#ifndef PORT_INTERFACE_H
#define PORT_INTERFACE_H

#include  "../../LIB/STD_TYPES.h"

/* define for max number of pins per port  */
#define Max_Pins_Per_Port    8


/* Configuration Type Defines */
#define  Pre_compile_configration   0
#define  Post_compile_configration  1


/* Port Number Defines */
#define  TWO_Ports                  0
#define  THREE_Ports                1
#define  FOUR_Ports                 2

/* Port Defines */
#define MPORT_PORTA                   0
#define MPORT_PORTB                   1
#define MPORT_PORTC                   2
#define MPORT_PORTD                   3


/* Input Output Defines */
#define MPORT_INPUT_PU               0
#define MPORT_INPUT_PD               1
#define MPORT_OUTPUT_HIGH            2
#define MPORT_OUTPUT_LOW             3


/* Port status Defines */
#define  PORT_LOW                  0
#define  PORT_HIGH                 1

#define CONCAT_BITS_HELPER(bit7, bit6, bit5,bit4, bit3, bit2,bit1,bit0)  0b##bit7##bit6##bit5##bit4##bit3##bit2##bit1##bit0
#define CONCAT_BITS(bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0)         CONCAT_BITS_HELPER(bit7, bit6, bit5,bit4, bit3, bit2,bit1,bit0)

typedef enum
{
	MPORT_enu_INPUT_PU,
	MPORT_enu_INPUT_PD,
	MPORT_enu_OUTPUT_HIGH,
	MPORT_enu_OUTPUT_LOW

}MPORT_ENU_PIN_CONFIGRATIONS_t;


typedef enum
{
	MPORT_enuPort_A,
	MPORT_enuPort_B,
	MPORT_enuPort_C,
	MPORT_enuPort_D
	
}MPORT_enuPORT_OPTS_t ;

typedef enum
{
	MPORT_enuPin_0,
	MPORT_enuPin_1,
	MPORT_enuPin_2,
	MPORT_enuPin_3,
	MPORT_enuPin_4,
	MPORT_enuPin_5,
	MPORT_enuPin_6,
	MPORT_enuPin_7
	
}MPORT_enuPIN_OPTS_t;

typedef enum 
{
	MPORT_enuLOW ,
	MPORT_enuHIGH

}PORT_enuSTATE_OPTS_t;

typedef enum
{
 MPORT_enuOK,
 MPORT_enuInvalidPin,
 MPORT_enuInvalidPort,
 MPORT_enuInvalidConfigration
}MPORT_enuPortErrorStatus_t;

typedef struct 
{
	MPORT_enuPORT_OPTS_t           Port;
	MPORT_enuPIN_OPTS_t            Pin ;
	MPORT_ENU_PIN_CONFIGRATIONS_t  Mode;

}MPORT_strConfig_t;



void PORT_voidPortInit(void);

/*
 * Function: MPORT_enuSetConfig
 * ----------------------------
 * Configures the mode of a specific pin on a given port based on the provided
 * configuration structure (MPORT_strConfig_t).
 *
 * Parameters:
 *   - Add_strPinConfig: Pointer to the configuration structure specifying the
 *                       port, pin, and desired mode.
 *
 * Returns:
 *   - MPORT_enuPortErrorStatus_t: Error status indicating the success or failure
 *                                 of the configuration process.
 *
 * Configuration Options (Mode):
 *   - MPORT_enu_INPUT_PU: Configure the pin as an input with pull-up resistor enabled.
 *   - MPORT_enu_INPUT_PD: Configure the pin as an input with pull-down resistor enabled.
 *   - MPORT_enu_OUTPUT_HIGH: Configure the pin as an output with an initial high state.
 *   - MPORT_enu_OUTPUT_LOW: Configure the pin as an output with an initial low state.
 *
 * Configuration Process:
 *   - The function validates the pin number against the maximum pins per port (Max_Pins_Per_Port).
 *   - Based on the specified port, pin, and mode, the corresponding data direction register (DDRx)
 *     and port register (PORTx) are manipulated to achieve the desired pin configuration.
 *
 * Error Handling:
 *   - If an invalid pin number is provided, the function returns MPORT_enuInvalidPin.
 *   - If an invalid port is provided, the function returns MPORT_enuInvalidPort.
 *   - If an invalid mode is provided, the function returns MPORT_enuInvalidConfiguration.
 *
 * Note: This code assumes that the macro values (Max_Pins_Per_Port) are correctly defined
 *       elsewhere in the code, and the error status provides feedback on the success or failure
 *       of the configuration process.
 */
MPORT_enuPortErrorStatus_t MPORT_enuSetConfig(MPORT_strConfig_t* Add_strPinConfig);


#endif
