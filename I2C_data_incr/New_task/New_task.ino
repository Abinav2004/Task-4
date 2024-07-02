//including wire.h library to work on data transmission
#include<Wire.h>

//-----------------------------------------variable declaration-------------------------------------
uint8_t Send_Array[6]={1,2,3,4,5,6}; //Array to be transmitted to Stm32 board via I2C
int slave_Address =12;//Respective slave address of I2C set in Stm32

//-----------------------------------------function declaration-----------------------------------------
void Data_transmit(uint8_t data[6]);//Declaration of function to transmit data

//-----------------------------------------function definition-------------------------------------
void Data_transmit(uint8_t data[6])
{
  Wire.beginTransmission(slave_Address);// begin transmission to the respective slave address, when no slave address it acts as master or slave address=127
  Wire.write(data,6);//
  uint8_t status=Wire.endTransmission();// ends the transmission to the slave
  if(status==0) // checks the error code obtained during transmission
  {
    Serial.println("transmitted data ");
  }
}

void setup() {
  Wire.begin();
  Serial.begin(9600);
}


void loop() {
Data_transmit(Send_Array);// calling the function
delay(1000);
}
