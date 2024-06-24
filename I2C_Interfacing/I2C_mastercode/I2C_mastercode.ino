#include <Wire.h>
int i=0;
#define STM32_ADDRESS 0x12// Replace with your STM32 I2C address found during scanning

void setup() {
  Wire.begin(); // Initialize I2C bus
  Serial.begin(9600); // Initialize Serial communication for debugging
}

void loop() {
  uint8_t maindata[6];
  for( i=0 ; i<6 ; i++)
  {
    Serial.println("Enter the data to be sent? ");
    while(Serial.available()==0){

    }
    uint8_t datas=Serial.parseInt();
    Serial.println(datas);
    maindata[i]=datas;
  }
  
  Wire.beginTransmission(STM32_ADDRESS); // Start transmission to STM32
  Wire.write(maindata, 6); // Send 6 bytes of data
  uint8_t status = Wire.endTransmission(); // End transmission and get status
  
  if (status == 0) {
    Serial.println("Transmission successful");
  } else {
    Serial.print("Transmission failed. Status code: ");
    Serial.println(status);
  }
  
  delay(1000); // Delay before next transmission
}
