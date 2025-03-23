/*
 * @Author: wyiwei1 wyiwei@seas.upenn.edu
 * @Date: 2025-03-18 22:48:58
 * @LastEditors: wyiwei1 wyiwei@seas.upenn.edu
 * @LastEditTime: 2025-03-23 17:27:01
 * @FilePath: \final-project-a07g-a14g-t11-keep-real\CLI Starter Code\src\CliThread\CliThread.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/**********************************************************************//**
* @file      CliThread.h
* @brief     File for the CLI Thread handler. Uses FREERTOS + CLI
* @author    Eduardo Garcia
* @date      2020-02-15

******************************************************************************/

#pragma once

#include "asf.h"
#include "SerialConsole.h"
#include "FreeRTOS_CLI.h"

// Add firmware version definition
#define FIRMWARE_VERSION "0.0.1"

#define CLI_TASK_SIZE	256		///<STUDENT FILL
#define CLI_PRIORITY (configMAX_PRIORITIES - 1) ///<STUDENT FILL
#define CLI_TASK_DELAY 150	///STUDENT FILL

#define MAX_INPUT_LENGTH_CLI    100	//STUDENT FILL
#define MAX_OUTPUT_LENGTH_CLI   130	//STUDENT FILL

#define CLI_MSG_LEN						16
#define CLI_PC_ESCAPE_CODE_SIZE			4
#define CLI_PC_MIN_ESCAPE_CODE_SIZE		2


#define ASCII_BACKSPACE					0x08
#define ASCII_DELETE                    0x7F
#define ASCII_WHITESPACE				0x20
#define ASCII_ESC						27


BaseType_t xCliClearTerminalScreen( char *pcWriteBuffer,size_t xWriteBufferLen,const int8_t *pcCommandString );

#define	CLI_COMMAND_CLEAR_SCREEN		"cls"
#define CLI_HELP_CLEAR_SCREEN			"cls: Clears the terminal screen\r\n"
#define CLI_CALLBACK_CLEAR_SCREEN		(pdCOMMAND_LINE_CALLBACK)xCliClearTerminalScreen
#define CLI_PARAMS_CLEAR_SCREEN			0

// 添加 version 命令的定义
#define CLI_COMMAND_VERSION             "version"
#define CLI_HELP_VERSION                "version: Prints the firmware version\r\n"
#define CLI_CALLBACK_VERSION            (pdCOMMAND_LINE_CALLBACK)CLI_PrintVersion
#define CLI_PARAMS_VERSION              0

// 添加 ticks 命令的定义
#define CLI_COMMAND_TICKS               "ticks"
#define CLI_HELP_TICKS                  "ticks: Prints the number of ticks since the scheduler was started\r\n"
#define CLI_CALLBACK_TICKS              (pdCOMMAND_LINE_CALLBACK)CLI_PrintTicks
#define CLI_PARAMS_TICKS                0

void vCommandConsoleTask( void *pvParameters );

BaseType_t CLI_GetImuData( int8_t *pcWriteBuffer,size_t xWriteBufferLen,const int8_t *pcCommandString );
BaseType_t CLI_OTAU( int8_t *pcWriteBuffer,size_t xWriteBufferLen,const int8_t *pcCommandString );
BaseType_t CLI_NeotrellisSetLed( int8_t *pcWriteBuffer,size_t xWriteBufferLen,const int8_t *pcCommandString );
BaseType_t CLI_NeotrellProcessButtonBuffer( int8_t *pcWriteBuffer,size_t xWriteBufferLen,const int8_t *pcCommandString );
BaseType_t CLI_DistanceSensorGetDistance( int8_t *pcWriteBuffer,size_t xWriteBufferLen,const int8_t *pcCommandString );
BaseType_t CLI_ResetDevice( int8_t *pcWriteBuffer,size_t xWriteBufferLen,const int8_t *pcCommandString );
BaseType_t CLI_SendDummyGameData( int8_t *pcWriteBuffer,size_t xWriteBufferLen,const int8_t *pcCommandString );

// 添加新命令的函数声明
BaseType_t CLI_PrintVersion( int8_t *pcWriteBuffer,size_t xWriteBufferLen,const int8_t *pcCommandString );
BaseType_t CLI_PrintTicks( int8_t *pcWriteBuffer,size_t xWriteBufferLen,const int8_t *pcCommandString );


