#include <arduino.h>
#include <ESP8266WiFi.h>
#include <Servo.h>

// In deze file staan alle voorzieningen om het ledstripje van 6 pixels leds aan te sturen

#include <FastLED.h>
#define DATA_PIN D7 // deze pin, GPIO13 (D7) geeft de data door naar de ledstrip
#define NUM_LEDS 6 // We hebben 6 leds op onze ledstrip
CRGB leds[NUM_LEDS];

int LoterijGetal;
int rood;
int groen;
int blauw;

Servo ServoDeksel; 
#define DEKSEL_DICHT 75  // Deksel dicht is 0 graden van de servo
#define DEKSEL_OPEN  5 // Deksel open is 180 graden van de servo
#define DEKSEL_KIER  40 // Deksel open is 180 graden van de servo





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

void setup() {
  // Alle code in dit setup deel wordt alleen bij opstarten 1x uitgevoerd
  WiFi.mode(WIFI_OFF); // geen wifi functies, spaart stroom ook
  
  // hier de servo's aansluitingen opgeven en ze in de rust stand zetten, armpje in en deksel dicht
  ServoDeksel.attach(0, 500, 2500); // gele aansluiting GPIO0 of ook wel D3 genoemd
  ServoDeksel.write(DEKSEL_DICHT);  

  // de schakelaar is aangesloten op massa (G) en ingang D2 (GPIO4)
  // de ingang word ook voorzien van een positieve spanning om de stand van de schakelaar te kunnen detecteren
  pinMode(4, INPUT_PULLUP);

  // dit is nodig om het stripje met de 6 leds te laten werken
  SetupLedStrip();
   
}
