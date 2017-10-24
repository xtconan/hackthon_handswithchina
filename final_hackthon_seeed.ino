


// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            2

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      55

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 150; // delay for half a second
const int parentleft_touch_pin=4;
const int parentright_touch_pin=5;
const int childleft_touch_pin=6;
const int childright_touch_pin=7;
const int ledpin=8;
int currentlednumber = 0;


void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(9600);


  //touchsensor
  
  pinMode(parentleft_touch_pin, INPUT);
  pinMode(parentright_touch_pin, INPUT);
  pinMode(childleft_touch_pin, INPUT);
  pinMode(childright_touch_pin, INPUT);



pinMode(8, OUTPUT); 
digitalWrite(8, LOW); 

    
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    for(int i=0;i<30;i++)
    {
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    }
  
}





void loop() {
  
if(currentlednumber<30)
{

  //touchsensor

  int parentleftvalue=digitalRead(parentleft_touch_pin);
  int parentrightvalue=digitalRead(parentright_touch_pin);
  int childleftvalue=digitalRead(childleft_touch_pin);
  int childrightvalue=digitalRead(childright_touch_pin);
Serial.println(parentleftvalue);
Serial.println(parentrightvalue);
Serial.println(childleftvalue);
Serial.println(childrightvalue);
  Serial.println(parentrightvalue);
    int i=0;
    if(parentleftvalue==1&&childleftvalue==1&&childrightvalue==1)
    {



    i=currentlednumber;
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
 //   pixels.setPixelColor(i, pixels.Color(255*i/NUMPIXELS,155,0)); // Moderately bright green color.
    pixels.setPixelColor(i, pixels.Color(250,250,250)); // Moderately bright green color.
    currentlednumber++;
   
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(80); // Delay for a period of time (in milliseconds).

    
       if(currentlednumber==30)
    {
       delay(100); 
       digitalWrite(8, HIGH); 
       delay(10000); 
       digitalWrite(8, LOW);
    }

    
  }else
    {

    
    if(currentlednumber>0)
    {
      int j=currentlednumber;
    pixels.setPixelColor(j, pixels.Color(0,0,0)); // Moderately bright green color.
    currentlednumber--;
    pixels.show(); // This sends the updated pixel color to the hardware.
    
    
    delay(40); // Delay for a period of time (in milliseconds).
   
   
    }
    }

}
else
{
  currentlednumber=10;
  Serial.println(currentlednumber);
 for(int i=0;i<30;i++)
 {
    pixels.setPixelColor(i, pixels.Color(4,4,4));
    delay(40);

 }
}

}

//

  
/*
  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(255*i/NUMPIXELS,155,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).
   

  }
  */



