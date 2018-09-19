//
//  tools.cpp
//  PCSCTool
//
//  Created by 刘维凯 on 2018/9/19.
//  Copyright © 2018年 刘维凯. All rights reserved.
//

#include <stdio.h>
#include "stdAfx.h"
#include <string>

using namespace std;

void StringToByte(const char *pStr, size_t i32Length, BYTE *bBuffer,uint32_t &ui32BufferLength)
{
    size_t iTempLen = strlen(pStr);
    size_t i32XLength = (iTempLen > i32Length ? i32Length : iTempLen) / 2;
    for(uint32_t ui32Count = 0; ui32Count < i32XLength; )
    {
        if(i32XLength - ui32Count >= 8)
        {
            sscanf(pStr + 2 * ui32Count, "%016llX", (uint64_t *)(&bBuffer[ui32Count]));
            *(uint64_t *)(&bBuffer[ui32Count]) = htonll(*((uint64_t *)(&bBuffer[ui32Count])));
            ui32Count += 8;
        }
        else if(i32XLength - ui32Count >= 4)
        {
            sscanf(pStr + 2 * ui32Count, "%08X", (uint32_t *)(&bBuffer[ui32Count]));
            *(uint32_t *)(&bBuffer[ui32Count]) = htonl(*((uint32_t *)(&bBuffer[ui32Count])));
            ui32Count += 4;
        }
        else if(i32XLength - ui32Count >= 2)
        {
            uint32_t ui32Temp = 0;
            sscanf(pStr + 2 * ui32Count, "%04X", &ui32Temp);
            *(uint16_t *)(&bBuffer[ui32Count]) = htons((uint16_t)ui32Temp);
            ui32Count += 2;
        }
        else
        {
            uint32_t ui32Temp = 0;
            sscanf(pStr + 2 * ui32Count, "%02X", &ui32Temp);
            bBuffer[ui32Count] = ui32Temp;
            ui32Count += 1;
        }
        ui32BufferLength = ui32Count;
    }
}

void StringToByte(const char *pStr, size_t i32Length, BYTE *bBuffer)
{
    size_t iTempLen = strlen(pStr);
    size_t i32XLength = (iTempLen > i32Length ? i32Length : iTempLen) / 2;
    for(uint32_t ui32Count = 0; ui32Count < i32XLength; )
    {
        if(i32XLength - ui32Count >= 8)
        {
            sscanf(pStr + 2 * ui32Count, "%016llX", (uint64_t *)(&bBuffer[ui32Count]));
            *(uint64_t *)(&bBuffer[ui32Count]) = htonll(*((uint64_t *)(&bBuffer[ui32Count])));
            ui32Count += 8;
        }
        else if(i32XLength - ui32Count >= 4)
        {
            sscanf(pStr + 2 * ui32Count, "%08X", (uint32_t *)(&bBuffer[ui32Count]));
            *(uint32_t *)(&bBuffer[ui32Count]) = htonl(*((uint32_t *)(&bBuffer[ui32Count])));
            ui32Count += 4;
        }
        else if(i32XLength - ui32Count >= 2)
        {
            uint32_t ui32Temp = 0;
            sscanf(pStr + 2 * ui32Count, "%04X", &ui32Temp);
            *(uint16_t *)(&bBuffer[ui32Count]) = htons((uint16_t)ui32Temp);
            ui32Count += 2;
        }
        else
        {
            uint32_t ui32Temp = 0;
            sscanf(pStr + 2 * ui32Count, "%02X", &ui32Temp);
            bBuffer[ui32Count] = ui32Temp;
            ui32Count += 1;
        }
    }
}

void StringToByte(const char *pStr, BYTE *bBuffer)
{
    size_t i32Length = strlen(pStr);
    StringToByte(pStr, i32Length, bBuffer);
}

void ByteToString(BYTE *bBuffer, size_t i32Length, char *pStr)
{
    for(int32_t i32Count = 0; i32Count < i32Length; )
    {
        if(i32Length - i32Count >= 8)
        {
            sprintf(pStr + 2 * i32Count, "%016llX", htonll(*((uint64_t *)(&bBuffer[i32Count]))));
            i32Count += 8;
        }
        else if(i32Length - i32Count >= 4)
        {
            sprintf(pStr + 2 * i32Count, "%08X", htonl(*((uint32_t *)(&bBuffer[i32Count]))));
            i32Count += 4;
        }
        else if(i32Length - i32Count >= 2)
        {
            sprintf(pStr + 2 * i32Count, "%04X", htons(*((uint16_t *)(&bBuffer[i32Count]))));
            i32Count += 2;
        }
        else
        {
            sprintf(pStr + 2 * i32Count, "%02X", *((uint8_t *)(&bBuffer[i32Count])));
            i32Count += 1;
        }
    }
}

void ByteToString(BYTE *bBuffer, size_t i32Length, string &s)
{
    s = "";
    s.resize(i32Length * 2 + 1);
    char *p = (char *)s.data();
    ByteToString(bBuffer, i32Length, p);
    s.resize(i32Length * 2);
}

void ByteToString(const BYTE *bBuffer, size_t i32Length, char *pStr)
{
    for (int32_t i32Count = 0; i32Count < i32Length; )
    {
        if (i32Length - i32Count >= 8)
        {
            sprintf(pStr + 2 * i32Count, "%016llX", htonll(*((uint64_t *)(&bBuffer[i32Count]))));
            i32Count += 8;
        }
        else if (i32Length - i32Count >= 4)
        {
            sprintf(pStr + 2 * i32Count, "%08X", htonl(*((uint32_t *)(&bBuffer[i32Count]))));
            i32Count += 4;
        }
        else if (i32Length - i32Count >= 2)
        {
            sprintf(pStr + 2 * i32Count, "%04X", htons(*((uint16_t *)(&bBuffer[i32Count]))));
            i32Count += 2;
        }
        else
        {
            sprintf(pStr + 2 * i32Count, "%02X", *((uint8_t *)(&bBuffer[i32Count])));
            i32Count += 1;
        }
    }
}

void ByteToString(const BYTE *bBuffer, size_t i32Length, string &s)
{
    s = "";
    s.resize(i32Length * 2 + 1);
    char *p = (char *)s.data();
    ByteToString(bBuffer, i32Length, p);
    s.resize(i32Length * 2);
}
