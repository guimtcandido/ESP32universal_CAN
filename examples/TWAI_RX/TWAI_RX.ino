#include <Arduino.h>
#include <ESP32_CAN.h>

//GPIOS:  CANTX: GPIO4   CANRX: GPIO5 
//BaudRates: 1000 -> 1MBps
//            800 -> 800Kbps
//            500 -> 500Kbps
//            250 -> 250Kbps
//            125 -> 125Kbps
//            100 -> 100Kbps
//             50 -> 50Kbps
//             25 -> 25Kbps  

TWAI_Interface CAN1(1000,4,5);  //argument 1 - BaudRate,  argument 2 - CAN_TX PIN,  argument 3 - CAN_RX PIN


uint32_t CAN_ID = 0;

uint8_t var = 0;

void setup() {
  Serial.begin(115200);
  Serial.print("STARTING...");

}

void loop() {

  // Method to print a unknown DLC
  CAN_ID = CAN1.RXpacketBegin(); //Get Frame ID

  Serial.print("Msg1 ID: ");
  Serial.print(CAN_ID,HEX);

  Serial.print("  Msg1 DLC: ");
   uint8_t CAN_DLC = CAN1.RXgetDLC();
  Serial.print(CAN_DLC);

  for(int i = 0; i < CAN1.RXgetDLC();i++){    //Function RXgetDLC() returns aboves frame DLC
      Serial.print("     ");  
      var = CAN1.RXpacketRead(i);  
      Serial.print(var); //Get FRAME DATA
      
  }

  Serial.println("");
  delay(100); //Visual Delay

}