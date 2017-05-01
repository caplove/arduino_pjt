// DHT Temperature & Humidity Sensor
// Unified Sensor Library Example
// Written by Tony DiCola for Adafruit Industries
// Released under an MIT license.

// Depends on the following Arduino libraries:
// - Adafruit Unified Sensor Library: https://github.com/adafruit/Adafruit_Sensor
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - LCD 2004 Library : 추가해야함.마스터에서 수정함.다시마스터로 와서 수정함..

/* 1. 필요한 라이브러리 블러오기(import needed library)  --------------------------------------- */ 

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal_I2C.h>

/* 2. 선언하기(define) ------------------------------------------------------------ */

#define DHTPIN            7         // Pin which is connected to the DHT sensor.
// Uncomment the type of sensor in use:
//#define DHTTYPE           DHT11     // DHT 11 
#define DHTTYPE           DHT22     // DHT 22 (AM2302)
//#define DHTTYPE           DHT21     // DHT 21 (AM2301)
// See guide for details on sensor wiring and usage:
//   https://learn.adafruit.com/dht/overview



DHT_Unified dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
/* 상수와 변수 */

uint32_t delayMS;
int MoisturePin=6;
int PhotoPin=15;
int RelayPin=8;   //////////////////////////////////

/* ========================================================================= */ 
void setup()                  /*----( SETUP: 딱 한번만 실행되는 곳임...RUNS ONCE )----*/
{
pinMode(RelayPin,OUTPUT); ////////////////////////
  Serial.begin(9600);                                 // Initialize device.
  dht.begin();
  Serial.println("DHTxx Unified Sensor Example");    // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.println("Temperature");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" *C");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" *C");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" *C");  
  Serial.println("------------------------------------");
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.println("Humidity");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println("%");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println("%");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println("%");  
  Serial.println("------------------------------------");
  // Set delay between sensor readings based on sensor details.
  lcd.begin(20,4);         // initialize the lcd for 20 chars 4 lines, turn on backlight
  lcd.backlight();
  delayMS = sensor.min_delay / 1000;
}

/*------------------( LOOP  반복해서 실행되는 곳: RUNS CONSTANTLY )------------------------*/
void loop() 
{
  // Delay between measurements.
  delay(delayMS);
 // Get temperature event and print its value.
  sensors_event_t event;  
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println("Error reading temperature!");
  }
  else {
    Serial.print("Temperature: ");
    Serial.print(event.temperature);
    Serial.println(" *C");
    lcd.setCursor(0,0);
    lcd.print("temperature : ");
    lcd.print(event.temperature);
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println("Error reading humidity!");
  }
  else {
    Serial.print("Humidity: ");
    Serial.print(event.relative_humidity);
    Serial.println("%");
    lcd.setCursor(0,1);
    lcd.print("Humidity : ");
    lcd.print(event.relative_humidity);
  }
    float Moisture=analogRead(MoisturePin);  // analogRead()는 5V 기준으로 1024가 MAX로 읽힌다.따라서, 0 ~ 1023까지만 숫자로 가짐//
    Serial.print("Moisture :");
    Serial.println(Moisture);
    lcd.setCursor(0,2);
    lcd.print("Moisture : ");
    lcd.print(Moisture);
    float Photo=analogRead(PhotoPin);  // analogRead()는 5V 기준으로 1024가 MAX로 읽힌다.따라서, 0 ~ 1023까지만 숫자로 가짐//
    Serial.print("Photo :");
    Serial.println(Photo);
    lcd.setCursor(0,3);
    lcd.print("Photo : ");
    lcd.print(Photo);

if (Moisture < 900) {                   ////////////////////////////////
   digitalWrite(RelayPin,LOW);          /////////////////////////////   
  lcd.setCursor(0,0); lcd.print("WATER PLEASE !!!!!!");
  lcd.setCursor(0,1); lcd.print("WATER PLEASE !!!!!!");
  lcd.setCursor(0,2); lcd.print("WATER PLEASE !!!!!!");
  lcd.setCursor(0,3); lcd.print("WATER PLEASE !!!!!!");  
   }                      
else if (Moisture >899) {
     digitalWrite(RelayPin,HIGH);          /////////////////////////////
}
}

