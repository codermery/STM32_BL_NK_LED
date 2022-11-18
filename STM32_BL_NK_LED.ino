/*
  Blink onboard LED at 0.1 second interval
*/
/*
void setup() {
  // initialize digital pin PB2 as an output.
  pinMode(PC13, OUTPUT); // LED connect to pin PB2
}
void loop() {
  digitalWrite(PC13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);               // wait for 100mS
  digitalWrite(PC13, LOW);    // turn the LED off by making the voltage LOW
  delay(100);               // wait for 100mS
}*/

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bmp;

HardwareSerial Serial2(USART2);   // PA3  (RX)  PA2  (TX)

void setup() 
{
    Serial2.begin(115200);
    bmp.begin(0x76);        
}
void loop() 
{
    Serial2.print("Temperat: ");   
    Serial2.println(bmp.readTemperature(),1);
    Serial2.print("Humidity: ");
    Serial2.println(bmp.readHumidity(),1);
    Serial2.print("Pressure: ");     
    Serial2.println((bmp.readPressure()/100),1);              
    delay(1000);
}
