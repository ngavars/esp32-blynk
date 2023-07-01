/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
/* Comment this out to disable prints and save space */
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "auth-token-goes-here";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "wifi ssid";
char pass[] = "my wifi password";

// this is the ESP32 pin that controls the remote
const int buttonPin = 23;

// V2 is a Blynk led to give some feedback when the button is pressed
WidgetLED led(V2);

// V1 is a Blynk button for gate/remote clontroll
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); 
  Serial.print("V1 value is: ");
  Serial.println(pinValue);

  if (pinValue==1) {
    digitalWrite(buttonPin, HIGH);
    led.on();
  } else {
    digitalWrite(buttonPin, LOW);
    led.off();
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  // Setup physical button pin (active low)
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  Blynk.run();
}
