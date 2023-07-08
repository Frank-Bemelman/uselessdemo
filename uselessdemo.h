#include <arduino.h>
#include <ESP8266WiFi.h>
#include <Servo.h>

// In deze file staan alle voorzieningen om het ledstripje van 6 pixels leds aan te sturen

#include <FastLED.h>
#define DATA_PIN D7 // deze pin, GPIO13 (D7) geeft de data door naar de ledstrip
#define NUM_LEDS 6 // We hebben 6 leds op onze ledstrip
CRGB leds[NUM_LEDS];



void SetupLedStrip(void)
{ // koppelen van de leds aan een uitgang van de ESP8266 
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);

  // alle leds op zwart of uit
  for(int i=0; i<NUM_LEDS; i++){
        leds[i].setRGB(0, 0, 0);
  }
  FastLED.show();
  FastLED.show(); // 2x want de eerste call gaat vaak mis
}  
