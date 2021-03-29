#include "Adafruit_DHT.h"

#define DHTTYPE DHT22
#define DHTPIN 2 


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  	Serial.begin(9600); 
	dht.begin();
}

void loop() {
    // Read temperature as Celsius
	float t = dht.getTempCelcius();
    String temp = String(t);
    
    // Publish to webhook
    Particle.publish("temp", temp, PRIVATE);
    delay(30000);               // Wait for 30 seconds
}
