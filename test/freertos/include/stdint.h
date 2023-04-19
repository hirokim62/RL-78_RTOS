
#ifndef FREERTOS_STDINT
#define FREERTOS_STDINT
#ifndef _STDINT_H

/*******************************************************************************
 * THIS IS NOT A FULL stdint.h IMPLEMENTATION - It only contains the definitions
 * necessary to build the FreeRTOS code.  It is provided to allow FreeRTOS to be
 * built using compilers that do not provide their own stdint.h definition.
 *
 * To use this file:
 *
 *    1) Copy this file into the directory that contains your FreeRTOSConfig.h
 *       header file, as that directory will already be in the compilers include
 *       path.
 *
 *    2) Rename the copied file stdint.h.
 *
 */
#if 1
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef long int32_t;
typedef unsigned long uint32_t;
#endif
#endif
#endif /* FREERTOS_STDINT */
