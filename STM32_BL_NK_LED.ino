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
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme;

void setup() 
{
    Serial.begin(115200);
    bme.begin(0x76);        
}
void loop() 
{
    Serial.print("Temperat: ");   
    Serial.println(bme.readTemperature(),1);
    Serial.print("Humidity: ");
    Serial.println(bme.readHumidity(),1);
    Serial.print("Pressure: ");     
    Serial.println((bme.readPressure()/100),1);              
    delay(1000);
}
