#ifndef _H_BIT_BAND_
#define _H_BIT_BAND_

#define BITBAND(addr, bitnum) ((addr & 0xF0000000) + 0x02000000U + ((addr & 0xFFFFF) << 5U) + ((bitnum) << 2U))
#define MEM_ADDR(addr) *((volatile unsigned long *)(addr))
#define BIT_ADDR(addr, bitnum) MEM_ADDR(BITBAND(addr, bitnum))

// Change this header file to fit your stm32 board
#include "stm32f4xx.h"

//IO口地址映射
#define GPIOA_ODR_Addr (GPIOA_BASE + 0x14)
#define GPIOB_ODR_Addr (GPIOB_BASE + 0x14)
#define GPIOC_ODR_Addr (GPIOC_BASE + 0x14)
#define GPIOD_ODR_Addr (GPIOD_BASE + 0x14)
#define GPIOE_ODR_Addr (GPIOE_BASE + 0x14)
#define GPIOF_ODR_Addr (GPIOF_BASE + 0x14)
#define GPIOG_ODR_Addr (GPIOG_BASE + 0x14)
#define GPIOH_ODR_Addr (GPIOH_BASE + 0x14)
#define GPIOI_ODR_Addr (GPIOI_BASE + 0x14)

#define GPIOA_IDR_Addr (GPIOA_BASE + 0x10)
#define GPIOB_IDR_Addr (GPIOB_BASE + 0x10)
#define GPIOC_IDR_Addr (GPIOC_BASE + 0x10)
#define GPIOD_IDR_Addr (GPIOD_BASE + 0x10)
#define GPIOE_IDR_Addr (GPIOE_BASE + 0x10)
#define GPIOF_IDR_Addr (GPIOF_BASE + 0x10)
#define GPIOG_IDR_Addr (GPIOG_BASE + 0x10)
#define GPIOH_IDR_Addr (GPIOH_BASE + 0x10)
#define GPIOI_IDR_Addr (GPIOI_BASE + 0x10)

#define PAout(n) BIT_ADDR(GPIOA_ODR_Addr, n) //输出
#define PAin(n) BIT_ADDR(GPIOA_IDR_Addr, n)  //输入

#define PBout(n) BIT_ADDR(GPIOB_ODR_Addr, n)
#define PBin(n) BIT_ADDR(GPIOB_IDR_Addr, n)

#define PCout(n) BIT_ADDR(GPIOC_ODR_Addr, n)
#define PCin(n) BIT_ADDR(GPIOC_IDR_Addr, n)

#define PDout(n) BIT_ADDR(GPIOD_ODR_Addr, n)
#define PDin(n) BIT_ADDR(GPIOD_IDR_Addr, n)

#define PEout(n) BIT_ADDR(GPIOE_ODR_Addr, n)
#define PEin(n) BIT_ADDR(GPIOE_IDR_Addr, n)

#define PFout(n) BIT_ADDR(GPIOF_ODR_Addr, n)
#define PFin(n) BIT_ADDR(GPIOF_IDR_Addr, n)

#define PGout(n) BIT_ADDR(GPIOG_ODR_Addr, n)
#define PGin(n) BIT_ADDR(GPIOG_IDR_Addr, n)

#define PHout(n) BIT_ADDR(GPIOH_ODR_Addr, n)
#define PHin(n) BIT_ADDR(GPIOH_IDR_Addr, n)

#define PIout(n) BIT_ADDR(GPIOI_ODR_Addr, n)
#define PIin(n) BIT_ADDR(GPIOI_IDR_Addr, n)

#endif
