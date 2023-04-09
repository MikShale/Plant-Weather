#pragma once
#include "read_env.h"

void debug_start(){
  #if (DEBUG == 1)
  Serial.begin(9600);  //initialize serial monitor
  #endif
}

void debug_msg(){
  
  #if (DEBUG == 1)

  Serial.print("M1: ");
  Serial.println (valueSensor1);
  Serial.print("M2: ");
  Serial.println (valueSensor2);

  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print("Temperature: ");
  Serial.println(t);

  #endif
}
