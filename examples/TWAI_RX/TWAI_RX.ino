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

TWAI_Interface CAN1(1000);

uint32_t CAN_ID = 0;

uint8_t var1 = 0;
uint8_t var2 = 0;
uint8_t var3 = 0;

void setup() {
  Serial.begin(115200);
  Serial.print("STARTING...");

}

void loop() {

  // Method to print a unknown DLC
  CAN_ID = CAN1.RXpacketBegin(); //Get Frame ID

  Serial.print("Msg ID: ");
  Serial.print(CAN_ID,HEX);

  for(int i = 0; i < CAN1.RXgetDLC();i++){    //Function RXgetDLC() returns aboves frame DLC
      Serial.print("     ");    
      Serial.print(CAN1.RXpacketRead(i)); //Get FRAME DATA
      
  }

  Serial.println("");


  // Method to print a known DLC -- example DLC of 3 bytes -- max will be CAN1.RXpacketRead(7);
  CAN_ID = CAN1.RXpacketBegin(); //Get Frame ID

  Serial.print("Msg ID: ");
  Serial.print(CAN_ID,HEX);

  var1 = CAN1.RXpacketRead(0);
  var2 = CAN1.RXpacketRead(1);
  var3 = CAN1.RXpacketRead(2);

  Serial.print("     ");
  Serial.print(var1);
  Serial.print("     ");
  Serial.print(var2);
  Serial.print("     ");
  Serial.println(var3);
  
  
}
