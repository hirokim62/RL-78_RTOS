/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIESREGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2011, 2017 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_main.c
* Version      : CodeGenerator for RL78/G14 V2.05.00.03 [05 May 2017]
* Device(s)    : R5F104LE
* Tool-Chain   : CCRL
* Description  : This file implements main function.
* Creation Date: 2022/12/18
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_port.h"
#include "r_cg_serial.h"
/* Start user code for include. Do not edit comment generated here */
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"

uint8_t g_uart2_rx_buffer = 0U;    // UART0 receive buffer
uint8_t g_uart2_rx_error = 0U;     // UART0 receive error status
MD_STATUS g_uart2_tx_end = 0U;     // UART0 transmission end

static const uint8_t message_ST[7U] = {"START\r\n"};  // UART開始メチE�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E��E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�ージ
static const uint8_t message_OK[4U] = {"OK\r\n"};     // "T"が受信されたら、EOK"を送信
static const uint8_t message_ok[4U] = {"ok\r\n"};     // "t"が受信されたら、Eok"を送信
static const uint8_t message_UC[4U] = {"UC\r\n"};     // それ以外が受信されたら、EUC"を送信

TaskHandle_t g_xTaskHandle_test = NULL;
QueueHandle_t g_UARTReceiveQueue;
void vTask_test(void *pvParameters);
void xTaskTest(void);

/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
void R_MAIN_UserInit(void);

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    R_MAIN_UserInit();
    /* Start user code. Do not edit comment generated here */
    xTaskTest();

    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_MAIN_UserInit(void)
{
    /* Start user code. Do not edit comment generated here */
    EI();
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
void vApplicationSetupTimerInterrupt(void)
{
}

void vApplicationMallocFailedHook(void)
{
}

void vApplicationStackOverflowHook(void)
{
}

void vApplicationDaemonTaskStartupHook(void)
{
}

void vApplicationGetIdleTaskMemory(void)
{
}

void vApplicationGetTimerTaskMemory(void)
{
}
void vTask_test(void *pvParameters)
{
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = 10;
    char buff[256];
    xLastWakeTime = xTaskGetTickCount();
    g_UARTReceiveQueue = xQueueCreate(1, 16);
    
    // ここに来れ�EOK
    for (;;)
    {
	//vTaskDelayUntil( &xLastWakeTime, xFrequency );


	//xQueueReceive(g_UARTReceiveQueue, (void*)buff, portMAX_DELAY);
    
       // R_UART2_Send((unsigned char *)message_ST,7); //送信
	
	vTaskDelay( xFrequency );
    
    }
}

void xTaskTest(void)
{
    BaseType_t xReturned;
    xReturned = xTaskCreate(vTask_test, "", 256, 0, 1, &g_xTaskHandle_test);

    if (xReturned == pdPASS)
    {
        vTaskStartScheduler();
    }
    else
    {
        while (1)
        {
            NOP();
        }
    }
}
/* End user code. Do not edit comment generated here */
