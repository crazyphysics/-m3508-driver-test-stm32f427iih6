#include "drv_can.h"
#include "tsk_callback.h"
#include "drv_serial.h"
#include "can.h"
#include "usart.h"
#include "dvc_motor.h"
#include "dma.h"

uint8_t pid_motor_flag = 0;

// CAN接收回调函数
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    // Motor_HandleTypeDef hmotor_tmp;
    // Motor_GetParam(&hmotor_tmp);
    // hmotor[hmotor_tmp.id] = hmotor_tmp;
    Motor_GetParam(&hmotor1);

    can_rx_flag = 1;
}

// UART接收完成回调函数
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    Serial_RxEventCallback(huart, Size);
}

// 定时器周期中断回调函数
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    // TIM6提供1ms中断
    if(htim->Instance == TIM6)
    {
        static uint8_t pid_motor_count = 0;

        if(++pid_motor_count >= PID_MOTOR_PERIOAD)
        {
            pid_motor_count = 0;
            
            pid_motor_flag = 1;
        }
    }
}
