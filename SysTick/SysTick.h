#ifndef __H_SYSTICK
#define __H_SYSTICK

/**
 * AHB 预分频系数，默认 1
*/
#ifndef AHB_PRESCALE
#define AHB_PRESCALE 1
#endif

/**
 * 包含定时器 SysTick 相关寄存器的头文件
*/
#include <misc.h>

typedef unsigned char uint8;
typedef unsigned int uint32;

typedef void (*SysTickCallback)(void);

enum
{
    SYSTICK_STOP = 0,
    SYSTICK_START = 1
};

/**
 * 初始化 SysTick
 * @param _sysClock Cortex内核的时钟频率，单位 MHz
*/
void SysTick_Init(uint32 _sysClock);

/**
 * 启动或者停止 SysTick
 * @param cmd 启动为: SYSTICK_START，停止为: SYSTICK_STOP
*/
void SysTick_Enable(uint8 cmd);

/**
 * 设置异步的回调函数
 * @param _callback 当定时的时间到达之后会调用此函数
*/
void SysTick_SetCallback(SysTickCallback _callback);

/**
 * 设置定时器的定时时间，时间到达之后会调用设置好的回调函数
 * @param ms 要定时的 ms 数
*/
void SysTick_SetTime(uint32 ms);

/**
 * 设置定时器的定时时间，时间到达之后会调用设置好的回调函数
 * @param us 要定时的 us 数
*/
void SysTick_SetTimeUs(uint32 us);

/**
 * ms同步延时（即阻塞式的延时，不触发中断）
 * @param ms 要延时的 ms 数
*/
void SysTick_DelaySync(uint32 ms);

/**
 * us同步延时（即阻塞式的延时，不触发中断），过短的延时会导致较大误差，例如 1us
 * @param us 要延时的 us 数
*/
void SysTick_DelaySyncUs(uint32 us);

#endif
