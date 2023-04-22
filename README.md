# ESP32universal_CAN
Library for ESP32universal module


Library was built to drive the CAN/TWAI Controller of a ESP32 chips
In the example are available the functions needed to receive and transmit CAN/TWAI frames.


//BaudRates: 1000 -> 1MBps

//            800 -> 800Kbps

//            500 -> 500Kbps

//            250 -> 250Kbps

//            125 -> 125Kbps

//            100 -> 100Kbps

//             50 -> 50Kbps

//             25 -> 25Kbps

Functions:

_ _Initialize the driver by writing the following function before the void setup();_ _

**TWAI_Interface CAN1(BAUDRATE,TX_PIN,RX_PIN);**  

Transmitting Messages:

_ _Initialize a packet transmission by calling the function below_ _

**CAN1.TXpacketBegin(ID,EXTENDED);   EXTENDED is a boolean, if extended ID write as 1.


_ _Load a byte referred to the ID set above. You do not need to set DLC, it is automatically handled by the function as you add more packets to the message._ _

**CAN1.TXpacketLoad(Data Byte);    //Remember each packet only allows you to write a byte data**


_ _Call this function and the message will be transmitted_ _

**CAN1.TXpackettransmit();         //Transmit the message configured above**


Receiving Messages:


_ _Look if there is a message in the buffer. If yes a ID will be returned by the function._ _

**CAN1.RXpacketBegin();**


_ _Get Message size by calling the function below. It will return the amount of bytes._ _

**CAN1.RXgetDLC();**


_ _Get ID data which will return you the byte correspondent to the INDEX._ _

**CAN1.RXpacketRead(INDEX);**
