#include <SPI.h>
#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

#define DHTPIN 7
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

int chk;
float h;  //Stores humidity value
float t; //Stores temperature value


void setup() {
lcd.begin(20,4);
Serial.begin(9600);
dht.begin();
}

void loop() {
      delay(2000);

float t = dht.readTemperature();
float h = dht.readHumidity();
delay(10000);

lcd.setCursor(0,0);
lcd.print(t);
lcd.print(" Centigrade");
lcd.setCursor(0,1);
lcd.print(h);
lcd.print(" Humidity");
Serial.print(t);
Serial.print(" Centigrade");
Serial.print(" ");
Serial.print(h);
Serial.println(" Humidity");

}
