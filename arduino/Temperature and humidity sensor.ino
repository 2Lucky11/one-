/*esp32-sht3X温湿度传感器简单代码使用，
读取温度以及湿度的初步代码*/



#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_SHT31.h"

Adafruit_SHT31 sht31 = Adafruit_SHT31();

void setup()
{
Serial.begin(9600);
if (! sht31.begin(0x44))
{
Serial.println("Couldn't find SHT31");
while (1)
 delay(100);
}
}

void loop()
{
float t = sht31.readTemperature();
float h = sht31.readHumidity();

if (! isnan(t))
{
Serial.print("Temp *C = "); 
Serial.println(t);

}
else
{
Serial.println("Failed to read temperature");
}

if (! isnan(h))
{
Serial.print("Hum. % = ");
Serial.println(h);
}
else
{
Serial.println("Failed to read humidity");
}
Serial.println();
delay(1000);
}