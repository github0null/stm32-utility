#ifndef _H_OLED_1306
#define _H_OLED_1306

typedef unsigned int uint32;
typedef unsigned char uint8;
typedef uint8 bool;

typedef void (*WriteCmdCallBack)(uint8 cmd);
typedef void (*WriteDataCallBack)(uint8 _data);
typedef void (*WriteDataArrayCallBack)(uint8 *arr, uint32 len);

#define USE_8x16_ASCII_TABLE

#ifdef USE_8x16_ASCII_TABLE
extern uint8 code ascii_8x16[][2][8];
#define CHAR_8X16(_code) ((uint8(*)[2][8]) & ascii_8x16[(_code)-48])
#endif

#define OLED_DEVICE_ADDR 0x78

#define OLED_OFF 0xAE
#define OLED_ON 0xAF

#define OLED_MODE_SCREEN_NORMAL 0xA6
#define OLED_MODE_SCREEN_INVERSE 0xA7

#define OLED_MODE_DISPLAY_RESUME_RAM 0xA4
#define OLED_MODE_DISPLAY_IGNORE_RAM 0xA5

#define OLED_SET_DISPLAY_ROW_OFFSET 0xD3

#define OLED_CALC_START_ROW(row) (uint8)(0x40U | (row & 0x3FU))
#define OLED_CALC_START_PAGE(page) (uint8)(0xB0U | (page & 0x07U))

#define OLED_CALC_START_COLUMN_HIGH(col) (uint8)(((col & 0xF0U) >> 4) | 0x10)
#define OLED_CALC_START_COLUMN_LOW(col) (uint8)(col & 0x0F)

#define OLED_MODE_NORMAL_ROW 0xC0
#define OLED_MODE_INVERSE_ROW 0xC8

#define OLED_MODE_NORMAL_COLUMN 0xA0
#define OLED_MODE_INVERSE_COLUMN 0xA1

#define OLED_SET_RAM_ADDR_MODE 0x20
#define OLED_RAM_ADDR_MODE_HORIZONTAL 0x00
#define OLED_RAM_ADDR_MODE_VERTICAL 0x01
#define OLED_RAM_ADDR_MODE_PAGE 0x02

#define OLED_SET_DISPLAY_CONTRAST 0x81

void OLED_Init(WriteCmdCallBack writeCmdCallbk,
               WriteDataCallBack writeDataCallbk, WriteDataArrayCallBack writeDataArrayCallbk);

void OLED_SetColumn(uint32 x);
void OLED_SetPage(uint32 y);
void OLED_SetColumnAndPage(uint32 x, uint32 page);

#ifdef USE_8x16_ASCII_TABLE
void OLED_WriteString_8x16(char *str);
#endif

void OLED_WritePoint(uint32 x, uint32 y, bool val);
void OLED_WriteData(uint8 _data, uint32 x, uint32 page);

void OLED_WriteDataArray(uint8 *arr, uint8 len);

void OLED_WriteData_8x16(uint8 (*arr)[2][8]);
void OLED_WriteData_16x16(uint8 (*arr)[2][16]);

void OLED_ClearEndOfPage(uint8 page);
void OLED_ClearPage(uint8 page);
void OLED_ClearAll(void);

uint8 OLED_GetColumn(void);
uint8 OLED_GetPage(void);

#endif
