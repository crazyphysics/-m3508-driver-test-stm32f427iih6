#include "drv_can.h"
#include "tsk_callback.h"
#include "drv_serial.h"
#include "can.h"
#include "alg_pid.h"
#include "usart.h"
#include "dvc_motor.h"
#include "dma.h"

/**
 * @brief 初始化任务
 */
void setup(void)
{
    Serial_RxDMA_Init(&huart2);
    Motor_Init();
    PID_SetParam(hmotor[1].pid, 0.1f, 0.01f, 0);    // 自己测试好了再赋值
}


/**
 * @brief 主循环任务
 */
void loop(void)
{
    // 处理串口接收到的数据
    if(serial_rx_flag == 1)
    {
        serial_rx_flag = 0;

        // 解析串口指令并赋值
        PID_ParseSerialPack(hmotor1.pid, serial_rx_packet);
        // 串口回传确保接收
        Serial_Printf_DMA(&huart2, "%.1f,%.1f,%.1f,%.1f,%.1f,%.1f", hmotor1.pid->target, hmotor1.pid->actual, hmotor1.pid->output, hmotor1.pid->kp, hmotor1.pid->ki, hmotor1.pid->kd);
    }
    
    // PID控制
    if(pid_motor_flag == 1)
    {
        pid_motor_flag = 0;

        Motor_SetTargetRPM(&hmotor1, hmotor1.pid->target);
        Serial_Printf_DMA(&huart2, "data:%.2f,%.2f,%.2f,%.2f,%.2f,%.2f\n", hmotor1.pid->kp, hmotor1.pid->ki, hmotor1.pid->kd, hmotor1.pid->actual, hmotor1.pid->target, hmotor1.pid->output);
           
    }
}
