#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

DHT dht(2, DHT11); //pin for DHT11
LiquidCrystal_I2C lcd(0x27, 16, 2); //initialize lcd. adress and resolution


void setup() {
 dht.begin();          //initialize DHT11
 Serial.begin(9600);   //initialize serial monitor
  
 lcd.init();          //initialize lcd
 lcd.backlight();     //backlight ON
}
 
void loop() {
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  
  /*
  //For Debugging
  Serial.print("Humidity: ");
  //Serial.println(h);
  //Serial.print("Temperature: ");
  //Serial.println(t);
  */

  lcd.setCursor(0, 0); //pointer to firs character firs line
  
 //Print information about Temperature
  lcd.print("T:"); 
  lcd.print(t);
  lcd.write(223);         // Degree symbol not in Extended ASCII, but work
  lcd.print("C");

  //Print inf about humidity
  lcd.setCursor(0, 1);
  lcd.print("H:");  
  lcd.print(h);
  lcd.write(37);           // Percent symbol not in ASCII=

  //Take information about Moisture from two sensors
  int valueSensor1 = 100-(analogRead(A0)-190)*0.33;
  int valueSensor2 = 100-(analogRead(A2)-190)*0.33;

  /*
  //Debug Inf of Moisture 
  Serial.print("M1: ");
  Serial.println (valueSensor1);
  Serial.print("M2: ");
  Serial.println (valueSensor2);
  */

  // Next two prints of Moisture information
  lcd.setCursor(9, 0);
  lcd.print("M1:");  //Information in pointer
  lcd.print(valueSensor1);
  lcd.write(37);

  lcd.setCursor(9, 1);
  lcd.print("M2:");  //Information in pointer
  lcd.print(valueSensor2);
  lcd.write(37);


  delay(3000);
}