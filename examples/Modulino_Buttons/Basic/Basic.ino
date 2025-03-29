/*
 * Modulino Buttons - Basic
 *
 * This example code is in the public domain. 
 * Copyright (c) 2025 Arduino
 * SPDX-License-Identifier: MPL-2.0
 */

 #include <Modulino.h>

 ModulinoButtons buttons;
 
 bool button_a = false;
 bool button_b = false;
 bool button_c = false;
 
 void setup() {
   Serial.begin(9600);
   Modulino.begin();
   buttons.begin();
   //function to control the LEDs on top of each button
   buttons.setLeds(button_a, button_b, button_c);
 }
 
 void loop() {
   //request new data from the Modulino buttons
   if (buttons.update()) {
     //Check if the buttons has been pressed
     if (buttons.isPressed(0)) {
       Serial.println("Button A pressed!");
       button_a = !button_a;
     } else if (buttons.isPressed(1)) {
       Serial.println("Button B pressed!");
       button_b = !button_b;
     } else if (buttons.isPressed(2)) {
       Serial.println("Button C pressed!");
       button_c = !button_c;
     }
     
     buttons.setLeds(button_a, button_b, button_c);
   }
 }