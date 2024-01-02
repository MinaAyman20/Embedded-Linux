#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../PORT/MPort_Interface.h"



typedef enum 
{

DIO_enu_OK                   ,
DIO_enu_NOK                  ,
DIO_enu_INVALID_PORT_NUM     ,
DIO_enu_INVALID_PIN_NUM      ,
DIO_enu_INVALID_CONFIGRATION ,
DIO_enu_NULL_PTR             ,
DIO_enu_INVALID_STATE        

}DIO_enuErrorState_t ;


typedef enum 
{
	DIO_enuPort_A,
	DIO_enuPort_B,
	DIO_enuPort_C,
	DIO_enuPort_D
	
}DIO_enuPORT_OPTS_t ;

typedef enum 
{
	DIO_enuPin_0,
	DIO_enuPin_1,
	DIO_enuPin_2,
	DIO_enuPin_3,
	DIO_enuPin_4,
	DIO_enuPin_5,
	DIO_enuPin_6,
	DIO_enuPin_7
	
}DIO_enuPIN_OPTS_t;


typedef enum
{
	DIO_enuOutput,
	DIO_enuInputInternalPullup,
	DIO_enuInputExternalPulldown
	
}DIO_enuCONFIGRATIONS_OPTS_t;

typedef enum 
{
	DIO_enuLow ,
	DIO_enuHigh 

}DIO_enuSTATE_OPTS_t;

typedef enum 
{
	DIO_enuPortLow = 0x00 ,
	DIO_enuPortHigh = 0xFF 

}DIO_enuPORTSTATE_OPTS_t;


/**
 * @brief Configure a specific pin in a given port for input or output.
 *
 * This function sets the configuration of a pin in a specified port
 * for either input or output. It also supports input with an internal
 * pull-up resistor or external pull-down resistor.
 *
 * @param Copy_enuPortNum:   The port to configure (A, B, C, or D).
 * @param Copy_enuPinNum:    The pin within the specified port.
 * @param Copy_enuConfigration: The desired configuration for the pin.
 *
 * @return DIO_enuErrorState_t: Indicates if the operation was successful
 *         or if there was an error.
 *         - DIO_enu_OK: Operation successful.
 *         - DIO_enu_INVALID_PORT_NUM: Invalid port number.
 *         - DIO_enu_INVALID_PIN_NUM: Invalid pin number.
 *         - DIO_enu_INVALID_CONFIGURATION: Invalid configuration option.
 *         - DIO_enu_NOK: General error or unsupported configuration.
 *
 * @note This function checks for valid parameters and configures the
 *       specified pin in the specified port accordingly. It uses
 *       bit manipulation to set or clear bits based on the desired
 *       configuration. If there's an error, an appropriate error state
 *       is returned.
 */


DIO_enuErrorState_t DIO_enuSetPinConfigration(DIO_enuPORT_OPTS_t Copy_enuPortNum , DIO_enuPIN_OPTS_t Copy_enuPinNum , DIO_enuCONFIGRATIONS_OPTS_t Copy_enuConfigration );

/**
 * @brief Configure the entire port for input or output based on the specified options.
 *
 * This function sets the configuration of all pins in a specified port for either
 * input or output. It also supports input with an internal pull-up resistor or
 * external pull-down resistor. The function handles different ports and their
 * configurations accordingly.
 *
 * @param Copy_enuPortNum:   The port to configure (A, B, C, or D).
 * @param Copy_enuConfigration: The desired configuration for the entire port.
 *
 * @return DIO_enuErrorState_t: Indicates if the operation was successful
 *         or if there was an error.
 *         - DIO_enu_OK: Operation successful.
 *         - DIO_enu_INVALID_PORT_NUM: Invalid port number.
 *         - DIO_enu_INVALID_CONFIGURATION: Invalid configuration option.
 *         - DIO_enu_NOK: General error or unsupported configuration.
 *
 * @note This function checks for valid parameters and configures the entire
 *       port based on the provided options. It uses bit manipulation to set
 *       or clear bits in the data direction register (DDRx) and the port register
 *       (PORTx) based on the desired configuration. If there's an error, an
 *       appropriate error state is returned.
 */


DIO_enuErrorState_t DIO_enuSetPortConfigration (DIO_enuPORT_OPTS_t Copy_enuPortNum , DIO_enuCONFIGRATIONS_OPTS_t Copy_enuConfigration );
 
/**
 * @brief Set the state (HIGH or LOW) of a specific pin in a given port.
 *
 * This function sets the state of a specified pin in a specified port
 * to either HIGH or LOW. It checks for valid parameters and uses bit
 * manipulation to set or clear the corresponding bit in the port register.
 *
 * @param Copy_enuPortNum:   The target port (A, B, C, or D).
 * @param Copy_enuPinNum:    The target pin within the specified port.
 * @param Copy_enuState:     The desired state for the specified pin (HIGH or LOW).
 *
 * @return DIO_enuErrorState_t: Indicates if the operation was successful
 *         or if there was an error.
 *         - DIO_enu_OK: Operation successful.
 *         - DIO_enu_INVALID_PORT_NUM: Invalid port number.
 *         - DIO_enu_INVALID_PIN_NUM: Invalid pin number.
 *         - DIO_enu_INVALID_STATE: Invalid state option.
 *         - DIO_enu_NOK: General error or unsupported state.
 *
 * @note This function checks for valid parameters and sets or clears
 *       the specified pin in the specified port based on the desired state.
 *       If there's an error, an appropriate error state is returned.
 */

DIO_enuErrorState_t DIO_enuSetPinValue(MPORT_enuPORT_OPTS_t Copy_enuPortNum , MPORT_enuPIN_OPTS_t Copy_enuPinNum , PORT_enuSTATE_OPTS_t Copy_enuState );
 
/**
 * @brief Set the state (High or Low) of all pins in a specified port.
 *
 * This function sets the state of all pins in a specified port to either
 * High or Low. It checks for valid parameters and assigns the specified
 * state to the entire port register.
 *
 * @param Copy_enuPortNum:   The target port (A, B, C, or D).
 * @param Copy_enuPortState: The desired state for the entire port (High or Low).
 *
 * @return DIO_enuErrorState_t: Indicates if the operation was successful
 *         or if there was an error.
 *         - DIO_enu_OK: Operation successful.
 *         - DIO_enu_INVALID_PORT_NUM: Invalid port number.
 *         - DIO_enu_INVALID_STATE: Invalid state option.
 *         - DIO_enu_NOK: General error or unsupported state.
 *
 * @note This function checks for valid parameters and assigns the specified
 *       state to all pins in the specified port. If there's an error, an
 *       appropriate error state is returned.
 */

DIO_enuErrorState_t DIO_enuSetPortValue(DIO_enuPORT_OPTS_t Copy_enuPortNum ,DIO_enuPORTSTATE_OPTS_t Copy_enuPortState ); 
 
/**
 * @brief Get the value (High or Low) of a specific pin in a given port.
 *
 * This function retrieves the current state (High or Low) of a specified pin
 * in a specified port. It checks for valid parameters and returns the pin value
 * through a pointer provided by the user.
 *
 * @param Copy_enuPortNum:    The target port (A, B, C, or D).
 * @param Copy_enuPinNum:     The target pin within the specified port.
 * @param Add_pu8PinValue:    Pointer to a variable to store the retrieved pin value.
 *
 * @return DIO_enuErrorState_t: Indicates if the operation was successful
 *         or if there was an error.
 *         - DIO_enu_OK: Operation successful.
 *         - DIO_enu_INVALID_PORT_NUM: Invalid port number.
 *         - DIO_enu_INVALID_PIN_NUM: Invalid pin number.
 *         - DIO_enu_NULL_PTR: Null pointer provided.
 *         - DIO_enu_NOK: General error or unsupported operation.
 *
 * @note This function checks for valid parameters and retrieves the current
 *       state of the specified pin in the specified port using bit manipulation.
 *       The retrieved pin value is stored in the variable pointed to by
 *       Add_pu8PinValue. If there's an error, an appropriate error state is returned.
 */
DIO_enuErrorState_t DIO_enuGetPinValue(MPORT_enuPORT_OPTS_t Copy_enuPortNum , MPORT_enuPIN_OPTS_t Copy_enuPinNum , u8* Add_pu8PinValue);




#endif   
