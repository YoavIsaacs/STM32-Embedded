/**
  ******************************************************************************
  * @file    LCDConf.h
  * @author  MCD Application Team
  * @brief   Header for LCDConf.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#include "main.h"
#include "GUI.h"
#include "GUIDRV_Lin.h"

#ifndef LCDCONF_H
#define LCDCONF_H


typedef struct
{
  int32_t      address;          
  int32_t      pending_buffer;   
  int32_t      buffer_index;     
  int32_t      xSize;            
  int32_t      ySize;            
  int32_t      BytesPerPixel;
  LCD_API_COLOR_CONV   *pColorConvAPI;
}
LCD_LayerPropTypedef;

void LCD_WaitForDisplayCompletion( void );
void LCD_RefreshRequestedByApplication( void );

void DSI_IO_WriteCmd(uint32_t NbrParams, uint8_t *pParams);

#endif /* LCDCONF_H */
