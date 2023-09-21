//#include <WiFi.h>
//#include <WiFiClient.h>
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL60x7MDRI2"
#define BLYNK_TEMPLATE_NAME "Locker system"
#define BLYNK_AUTH_TOKEN "YfrXw7h9Pyvd7Hab6c3Rm9z08TVlshes"


#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>



char auth[] = BLYNK_AUTH_TOKEN;
 
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Galaxy A03s6014";
char pass[] = "ok12345678";

int L1 = D0;
int L2 = D1;
int L3 = D2;
int L4 = D3; // Define LED as an Integer (whole numbers) and pin D8 on Wemos D1 Mini Pro

// This function will be called every time button Widget
// in Blynk app writes values to the Virtual Pin V3


void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT); //Set the LED (D8) as an output
  pinMode(D4, OUTPUT); // for led inputs
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, INPUT); // input for magnetic sensor
  Blynk.begin(auth, ssid, pass);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, HIGH);
  digitalWrite(L4, HIGH);
  digitalWrite(D4, HIGH);
  digitalWrite(D5, HIGH);
  digitalWrite(D6, HIGH);
  digitalWrite(D7, HIGH);
  

}

void loop()
{
  
  
  Blynk.run();


 
}
// This function will be called every time button Widget
// in Blynk app writes values to the Virtual Pin V3
BLYNK_WRITE(V0) {
 int pinValue = param.asInt(); // Assigning incoming value from pin V3 to a variable
 if (pinValue == 1) {
    digitalWrite(L1, LOW); //if on then switch on the led
    digitalWrite(D4, LOW);
    // Turn LED on.
  } 
  if(pinValue==0) {
    digitalWrite(L1, HIGH);
    digitalWrite(D4, HIGH);
    // Turn LED off.
 }
  if(digitalRead(D8)==HIGH){
    digitalWrite(D4, HIGH);
    Blynk.virtualWrite(V0,0);
  }
}
BLYNK_WRITE(V1) {
 int pinValue = param.asInt(); // Assigning incoming value from pin V3 to a variable
 if (pinValue == 1) {
    digitalWrite(L2, LOW);
    digitalWrite(D5, LOW);// Turn LED on.
  } 
  else {
    digitalWrite(L2, HIGH);
    digitalWrite(D5, HIGH);// Turn LED off.
 }
}
BLYNK_WRITE(V2) {
 int pinValue = param.asInt(); // Assigning incoming value from pin V3 to a variable
 if (pinValue == 1) {
    digitalWrite(L3, LOW);
    digitalWrite(D6, LOW);// Turn LED on.
  } 
  else {
    digitalWrite(L3, HIGH);
    digitalWrite(D6, HIGH);// Turn LED off.
 }
}
BLYNK_WRITE(V3) {
 int pinValue = param.asInt(); // Assigning incoming value from pin V3 to a variable
 if (pinValue == 1) {
    digitalWrite(L4, LOW);
    digitalWrite(D7, LOW);
    // Turn LED on.
  } else {
    digitalWrite(L4, HIGH);
    digitalWrite(D7, HIGH);// Turn LED off.
 }
}
 
