# PCSCTool
CPU卡读写工具<br>
OS:osx<br>
device:ACR1251<br>
card:云南省高速公路etc云通卡<br>
 
测试数据<br>
m_hContext:1<br>
readername size is 57<br>
List Reader:<br> 
index:0 name:ACS ACR1251 1S CL Reader(2)<br>
index:1 name:ACS ACR1251 1S CL Reader(1)<br>
please input reader's index:1<br>
you choose index:1<br>
choose reader:ACS ACR1251 1S CL Reader(1)<br>
m_hCard:1<br>
please input apdu (input 'exit' to exit this loop):00A40000023F0000<br>
you input apdu:00A40000023F0000<br>
recv card data:6F15840E315041592E5359532E4444463031A5038801019000<br>
please input apdu (input 'exit' to exit this loop):00A4000002100100<br>
you input apdu:00A4000002100100<br>
recv card data:6F3F8409A00000000386980701A53200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000009000<br>
please input apdu (input 'exit' to exit this loop):00B095002B<br>
you input apdu:00B095002B<br>
recv card data:D4C6C4CF000000011610530100000000000011082016053020260530B2E2594430303036000000000005019000<br>
please input apdu (input 'exit' to exit this loop):exit<br>
you input apdu:exit<br>
stop<br>
Program ended with exit code: 0<br>

