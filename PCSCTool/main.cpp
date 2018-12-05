//
//  main.cpp
//  PCSCTool
//
//  Created by 刘维凯 on 2018/9/19.
//  Copyright © 2018年 刘维凯. All rights reserved.
//

#include <iostream>
#include <PCSC/winscard.h>
#include <map>
#include "stdAfx.h"
#include "tools.h"

using namespace std;

SCARDCONTEXT    m_hContext;
map<int,char *> mapReader;

int main(int argc, const char * argv[]) {
    
    SCARDHANDLE     m_hCard;
    
    int iResult = 0;
    iResult = SCardEstablishContext(SCARD_SCOPE_USER, NULL, NULL, &m_hContext);
    if(iResult != SCARD_S_SUCCESS){
        cerr << "Context error,code is " << hex << iResult << endl;
        return -1;
    }
    
    cout << "m_hContext:" << m_hContext << endl;
    
    char cReaderName[100];
    uint32_t ui32ReadNameSize = 100;
    
    iResult = SCardListReaders(m_hContext, NULL, cReaderName, &ui32ReadNameSize);
    if(iResult != SCARD_S_SUCCESS){
        cerr << "List Reader error,code is " << hex << iResult << endl;
        return -1;
    }
    
    cout << "readername size is " << ui32ReadNameSize << endl;
    
    uint32_t i = 0;
    cout<<"List Reader: " << endl;
    int iReaderIndex = 0;
    while(i < ui32ReadNameSize) {
        if(strlen(cReaderName + i) > 0){
            mapReader.insert(map<int, char *>::value_type(iReaderIndex, cReaderName + i));
            cout<< "index:" << iReaderIndex << " name:" << cReaderName + i << endl;
            iReaderIndex += 1;
        }
        i += strlen(cReaderName);
        i ++;
    }
    
    int iChooseReaderIndex = 0;
    cout << "please input reader's index:";
    cin >> iChooseReaderIndex;
    cout << "you choose index:" << iChooseReaderIndex << endl;
    cout << "choose reader:" << mapReader[iChooseReaderIndex] << endl;
    
    SCARD_IO_REQUEST io;
    io.cbPciLength = sizeof(SCARD_IO_REQUEST);
    
    iResult = SCardConnect(m_hContext, mapReader[iChooseReaderIndex], SCARD_SHARE_SHARED, SCARD_PROTOCOL_ANY, &m_hCard, &io.dwProtocol);
    if(iResult  !=  SCARD_S_SUCCESS) {
        cerr << "Connect Card error, code is " << hex << iResult << endl;
        return -1;
    }
    
    cout << "m_hCard:" << m_hCard << endl;
    
    while(true){
        string strSendApduCmd;
        cout << "please input apdu (input 'exit' to exit this loop):";
        cin >> strSendApduCmd;
        cout << "you input apdu:" << strSendApduCmd << endl;
        if(strSendApduCmd == "exit"){
            cout << "stop" << endl;
            break;
        }
        
        uint32_t ui32APDUCmdLen = 262;
        BYTE bSendAPDU[ui32APDUCmdLen];
        uint32_t ui32SendBufferLen = 0;
        BYTE bRecvData[ui32APDUCmdLen];
        StringToByte(strSendApduCmd.c_str(),strSendApduCmd.length(),bSendAPDU,ui32SendBufferLen);
        iResult = SCardTransmit(m_hCard, &io, bSendAPDU, ui32SendBufferLen, NULL, bRecvData, &ui32APDUCmdLen);
        if(iResult != SCARD_S_SUCCESS){
            cerr << "List Reader error,code is " << hex << iResult << endl;
            return -1;
        }
        
        string strRecvData;
        ByteToString(bRecvData, ui32APDUCmdLen, strRecvData);
        cout << "recv card data:" << strRecvData << endl;
    }
    
    return 0;
}
