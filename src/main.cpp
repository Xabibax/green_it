/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"
#include "SPI.h"
#include "EEPROM.h"
#include "RH_RF69.h"
// #include <Bouton.h>
#include "LowPower.h"
#include "LoRa.h"
#include "T2WhisperNode.h"

#ifndef LED
#define LD1 
#endif

// Use pin 4 as wake up pin
const int wakeUpPin = 4;
const int LED_BLUE = 6;
const int LED_RED  = 9;
void wakeUp()
{
    // Just a handler for the pin interrupt.
}

T2Flash flash;

void setup()
{
  // initialize LED digital pin as an output.
  Serial.begin(9600);
  // Bouton lol = new Bouton(0);
  LoRa.setPins(10,7,2);
  if (!LoRa.begin(868E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  } 
}
void loop()

{

  LoRa.sleep();
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); 
  // LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); 
  // LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); 
  // LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); 
  // LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF); 
  // // LowPower.powerDown(SLEEP_FOREVER, ADC_ON, BOD_OFF); 
  // // LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_ON); 
  // // LowPower.powerDown(SLEEP_FOREVER, ADC_ON, BOD_ON); 

  // // LowPower.powerStandby(SLEEP_FOREVER, ADC_OFF, BOD_OFF); 
  // // LowPower.powerStandby(SLEEP_FOREVER, ADC_ON, BOD_OFF); 
  // // LowPower.powerStandby(SLEEP_FOREVER, ADC_OFF, BOD_ON); 
  // // LowPower.powerStandby(SLEEP_FOREVER, ADC_ON, BOD_ON); 

  // // LowPower.powerSave(SLEEP_FOREVER, ADC_OFF, BOD_OFF, TIMER2_OFF  ); 
  // // LowPower.powerSave(SLEEP_FOREVER, ADC_ON, BOD_OFF, TIMER2_OFF  ); 
  // // LowPower.powerSave(SLEEP_FOREVER, ADC_OFF, BOD_ON, TIMER2_OFF  ); 
  // // LowPower.powerSave(SLEEP_FOREVER, ADC_OFF, BOD_OFF, TIMER2_ON  ); 
  // // LowPower.powerSave(SLEEP_FOREVER, ADC_ON, BOD_ON, TIMER2_ON  ); 
  
  // // LowPower.idle(SLEEP_FOREVER, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF, SPI_OFF, USART0_OFF, TWI_OFF); 
  // // LowPower.idle(SLEEP_FOREVER, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF, SPI_OFF, USART0_OFF, TWI_ON); 
  // // LowPower.idle(SLEEP_FOREVER, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF, SPI_OFF, USART0_ON, TWI_OFF); 
  // // LowPower.idle(SLEEP_FOREVER, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF, SPI_ON, USART0_OFF, TWI_OFF); 
  // // LowPower.idle(SLEEP_FOREVER, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF, SPI_ON, USART0_ON, TWI_ON); 

  // LoRa.sleep();
  // flash.init(T2_WPN_FLASH_SPI_CS);
  // flash.powerDown();
  char radioBuf[10]={'0','1','2','3','4','5','6','7','8','9'};
  digitalWrite(LED_BLUE, HIGH);
  LoRa.setTxPower(2);
  digitalWrite(14, HIGH);
  Serial.print("Read pin A7 : ");
  Serial.print((7.282 * analogRead(7)) / 1024);
  Serial.print(" V");
  digitalWrite(14, LOW);
  for (size_t i = 0; i < 100; i++)
  {
    LoRa.beginPacket();
    LoRa.write(radioBuf,10);
    LoRa.endPacket();
  }
  delay(100);
  digitalWrite(LED_BLUE, LOW);

  LoRa.sleep();
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); 
  // LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); 
  // LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); 
  // LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); 
  // LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF); 

  digitalWrite(LED_RED, HIGH);
  LoRa.setTxPower(20);
  digitalWrite(14, HIGH);
  Serial.print("Read pin A7 : ");
  Serial.print((7.282 * analogRead(7)) / 1024);
  Serial.print(" V");
  digitalWrite(14, LOW);
  for (size_t i = 0; i < 100; i++)
  {
    LoRa.beginPacket();
    LoRa.write(radioBuf,10);
    LoRa.endPacket();
    
    digitalWrite(14, HIGH);
    Serial.print("Read pin A7 : ");
    Serial.print((7.282 * analogRead(7)) / 1024);
    Serial.print(" V");
    digitalWrite(14, LOW);
  }
  delay(100);
  digitalWrite(LED_RED, LOW);
}


