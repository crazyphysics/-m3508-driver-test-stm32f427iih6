# M3508 Driver Test (STM32F427IIH6)

#### 介绍
硬件平台为RoboMaster A板, 基于STM32F427IIH6, 使用CAN总线实现对无刷电机M3508+电调C620的控制

#### 目录
/Core目录为CubeMX自动生成的, main.c在这里  
/Middlewares目录为arm_math.lib库  
/User_alg目录为纯软件算法, 包括PID等  
/User_drv目录为重新封装的驱动  
/User_dvc目录为设备抽象, 使用到drv的驱动  
/User_tsk目录为任务调度相关, 包括中断回调, 主循环等  


#### 外设说明
##### CAN外设
电机使用CAN1, 高速CAN, 波特率1Mbps  
仅使用FIFO0, 过滤器为32位, 仅通过CAN_ID为0x200~0x208
##### UART外设
串口使用UART2, 波特率115200bps, 8N1  
MCU数据包: 纯文本, "data:%f,%f,%f,%f,%f,%f\n", 其中%f为具体数据  
上位机数据包: 纯文本, "KxFF.F\n", 其中'K'为包头, 'x'可为p/i/d/t, 分别表示为kp/ki/kd/target


#### 使用说明

1.  当前暂未测试, 也许有bug需要处理
2.  已在F103上完成相关编写与测试, 移植工作正在推进


#### 引脚图
![引脚图](https://gitee.com/liuyihui1/m3508-driver-test-stm32f427iih6/blob/master/%E5%BC%95%E8%84%9A%E5%9B%BE.png)


#### 参与贡献

1.  先与我本人联系 (RoboPioneer下位机小登)
2.  Fork 本仓库
3.  新建分支
4.  提交代码
5.  新建 Pull Request


#### 其他说明
1.  这不是正式项目, 仅练手
2.  每周去实验室机会不多, 玩板子机会有限
