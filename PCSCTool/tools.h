//
//  tools.h
//  PCSCTool
//
//  Created by 刘维凯 on 2018/9/19.
//  Copyright © 2018年 刘维凯. All rights reserved.
//

#ifndef tools_h
#define tools_h

#include "stdAfx.h"

using namespace std;

void StringToByte(const char *pStr, size_t i32Length, BYTE *bBuffer,uint32_t &szBufferLength);
void StringToByte(const char *pStr, size_t i32Length, BYTE *bBuffer);
void StringToByte(const char *pStr, BYTE *bBuffer);

void ByteToString(BYTE *bBuffer, size_t i32Length, char *pStr);
void ByteToString(BYTE *bBuffer, size_t i32Length, string &s);
void ByteToString(const BYTE *bBuffer, size_t i32Length, char *pStr);
void ByteToString(const BYTE *bBuffer, size_t i32Length, string &s);


#endif /* tools_h */
