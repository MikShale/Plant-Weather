#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Wire.h>

#pragma once

int valueSensor1;
int valueSensor2;
int h;
int t;

DHT dht(2, DHT11);                   //pin for DHT11
LiquidCrystal_I2C lcd(0x27, 16, 2);  //initialize lcd. adress and resolution


void read_env() {
  
  valueSensor1 = 100 - (analogRead(A0) - 190) * 0.33;
  valueSensor2 = 100 - (analogRead(A2) - 190) * 0.33;

  h = dht.readHumidity();
  t = dht.readTemperature();
}