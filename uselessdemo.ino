#include "uselessdemo.h"

// we gebruiken in het voorbeeld één servo motortje
// deze zijn aangesloten op massa (G) en 5 volt (VIN) voor de energie
// het stuurdraadjes van de servo's is aangesloten op D3
Servo ServoDeksel; 
#define DEKSEL_DICHT 75  // Deksel dicht is 0 graden van de servo
#define DEKSEL_OPEN  5 // Deksel open is 180 graden van de servo
#define DEKSEL_KIER  40 // Deksel open is 180 graden van de servo


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


int LoterijGetal;

void loop() {
  // dit is het hoofdprogramma, hier gebeurt het allemaal
  // het is een herhalende lus die continue en razendsnel doorlopen wordt
  
  if(digitalRead(4) == LOW)
  { // zolang de schakelaar dicht is
    leds[0].setRGB(255, 0, 0);
    leds[1].setRGB(255, 0, 0);
    leds[2].setRGB(255, 0, 0);
    leds[3].setRGB(255, 0, 0);
    leds[4].setRGB(255, 0, 0);
    leds[5].setRGB(255, 0, 0);
    ServoDeksel.write(DEKSEL_DICHT);  
  }
  else
  { leds[0].setRGB(0, 0, 255);
    leds[1].setRGB(0, 0, 255);
    leds[2].setRGB(0, 0, 255);
    leds[3].setRGB(0, 0, 255);
    leds[4].setRGB(0, 0, 255);
    leds[5].setRGB(0, 0, 255);
    ServoDeksel.write(DEKSEL_OPEN);  
  }  

  FastLED.show(); // en stuur het naar de ledstrip

  delay(100);


  // dit is het einde van de lus en springen we vanzelf weer naar boven, naar het begin van loop()
}
