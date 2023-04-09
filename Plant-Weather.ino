#define DEBUG 0

#include "debug_serial.h"
#include "constants_PW.h"
#include "read_env.h"



void setup() {
  dht.begin();      //initialize DHT11

  lcd.init();       //initialize lcd
  lcd.backlight();  //backlight ON

  debug_start();
}

void loop() {

  read_env();

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(t);
  lcd.write(DEGREE_ASCII);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("H:");
  lcd.print(h);
  lcd.write(PERSENT_ASCII);

  lcd.setCursor(9, 0);
  lcd.print("M1:");
  lcd.print(valueSensor1);
  lcd.write(PERSENT_ASCII);
  lcd.print(" ");

  lcd.setCursor(9, 1);
  lcd.print("M2:");
  lcd.print(valueSensor2);
  lcd.write(PERSENT_ASCII);
  lcd.print(" ");

  debug_msg();

  delay(3000);
}
