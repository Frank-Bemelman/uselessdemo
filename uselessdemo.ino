#include "uselessdemo.h"

// we gebruiken in dit voorbeeld één servo motortje en één ledstripje van 6 leds
// alle tekst die met twee schuine strepen begint, is enkel een notitie voor ons zelf
// met dat soort tekst doet de microcontroller niets

void loop() {
  // dit is het hoofdprogramma, hier gebeurt het allemaal
  // het is een herhalende lus die continue en razendsnel doorlopen wordt
  
  if(digitalRead(4) == HIGH)
  { // zolang de draadjes geen contact maken
    leds[0].setRGB(255, 0, 0); // deze drie getallen bepalen de kleur van rood, groen en blauw
    leds[1].setRGB(255, 0, 0);
    leds[2].setRGB(255, 0, 0);
    leds[3].setRGB(255, 0, 0);
    leds[4].setRGB(255, 0, 0);
    leds[5].setRGB(255, 0, 0);

//     rood = random(255); groen = random(255); blauw = random(255); 
//     leds[0].setRGB(rood, groen, blauw);
    
    
    ServoDeksel.write(0);  // zet de servo in nul graden stand
  }
  else // dus als de draadjes wel contact maken
  { leds[0].setRGB(0, 0, 255);
    leds[1].setRGB(0, 0, 255);
    leds[2].setRGB(0, 0, 255);
    leds[3].setRGB(0, 0, 255);
    leds[4].setRGB(0, 0, 255);
    leds[5].setRGB(0, 0, 255);
    ServoDeksel.write(180); // zet de servo in 180 graden stand  
  }  

  FastLED.show(); // en stuur het naar de ledstrip
  delay(100); // even een aantal milliseconden uitrusten 
  // dit is het einde van de lus en springen we vanzelf weer naar boven, naar het begin van loop()
}
