/********************************************
 * 
 *  RGB Blink sample using FastLED library
 *  by Sukesh Ashok Kumar
 * 
 ********************************************/
#include <FastLED.h>
#include <WiFi.h>


/* Enable the board you are using below */
//#define TINY_S3
#define FEATHER_S3
//#define PRO_S3

#ifdef TINY_S3
  #define DATA_PIN 18
  #define POWER_PIN 17
#endif

#ifdef FEATHER_S3
  #define DATA_PIN 40
  //#define POWER_PIN 17
#endif

#ifdef PRO_S3
  #define DATA_PIN 18
  //#define POWER_PIN 17
#endif


// How many leds in your strip?
#define NUM_LEDS 1

// Define the array of leds
CRGB leds[NUM_LEDS];

#define BRIGHTNESS 100

const char* ssid     = "ssid";
const char* password = "pw";

void setup() { 

  Serial.begin (115200);
  Serial.println ();

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed

#ifdef TINY_S3
  // Enable LED
  pinMode(POWER_PIN, OUTPUT);
  digitalWrite(POWER_PIN, HIGH);
#endif

  FastLED.setBrightness(BRIGHTNESS);


  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  
}

void loop() { 
  // Turn the LED on, then pause
  if (WiFi.status() != WL_CONNECTED)
    leds[0] = CRGB::Red;
  else
    leds[0] = CRGB::Green;

  FastLED.show();
  delay(500);

  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(500);

}
