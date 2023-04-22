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

Initialize the driver by writing the following function before the void setup();
TWAI_Interface CAN1(BAUDRATE,TX_PIN,RX_PIN);  

Transmitting Messages:

Initialize a packet transmission by calling the function below

CAN1.TXpacketBegin(ID,EXTENDED);   EXTENDED is a boolean, if extended ID write as 1.

Load a byte referred to the ID set above. You do not need to set DLC, it is automatically handled by the function as you add more packets to the message.

CAN1.TXpacketLoad(Data Byte);    //Remember each packet only allows you to write a byte data

Call this function and the message will be transmitted

CAN1.TXpackettransmit();         //Transmit the message configured above

Receiving Messages:

Look if there is a message in the buffer. If yes a ID will be returned by the function.

CAN1.RXpacketBegin();

Get Message size by calling the function below. It will return the amount of bytes.

CAN1.RXgetDLC();

Get ID data which will return you the byte correspondent to the INDEX.

CAN1.RXpacketRead(INDEX);
