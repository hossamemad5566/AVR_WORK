#ifndef HAL_RELAY_H_
#define HAL_RELAY_H_

/*--------------------------------------------------------------------------------------------*/
/*   SELECT MICROCONTROLERS PINS   */
/*--------------------------------------------------------------------------------------------*/
#define RELAY_PIN            PC7_PIN
/*--------------------------------------------------------------------------------------------*/
/*   SELECT PB_DEBOUNCING_TIME IN MILLI SECOND   */
/*--------------------------------------------------------------------------------------------*/


void Relay_voidInit(void);

void Relay_voidFlash(void);

void Relay_voidOff(void);

#endif
