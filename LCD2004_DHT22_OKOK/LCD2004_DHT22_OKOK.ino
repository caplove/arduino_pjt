
/* YourDuino.com Example Software Sketch
   DHT11 Humidity and Temperature Sensor test
   Displayed on I2C LCD Display
   Credits: Rob Tillaart
   http://arduino-info.wikispaces.com/PROJECT-Temp-Humidity-Display
   terry@yourduino.com */
   
/*-----( Import needed libraries )-----*/
#include <SPI.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>


/*-----( Declare objects )-----*/
// set the LCD address to 0x27 for a 20 chars 4 line display
// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

#define DHTPIN 7     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

/*-----( Declare Constants, Pin Numbers )-----*/



void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600); //(Remove all 'Serial' commands if not needed)
    dht.begin();
  lcd.begin(20,4);         // initialize the lcd for 20 chars 4 lines, turn on backlight
  lcd.backlight();
}/*--(end setup )---*/

void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
float t = dht.readTemperature();
float h = dht.readHumidity();
delay(5000);

//t = ((float)t)-3;
//if (isnan(t) || isnan(h)) {
//lcd.setCursor(5,1);
//lcd.println("fail");
//} else {
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
//}
}/* --(end main loop )-- */



