// This example shows how to connect to Cayenne using an ESP8266 and send/receive sample data.
// Make sure you install the ESP8266 Board Package via the Arduino IDE Board Manager and select the correct ESP8266 board before compiling. 

//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>
#include <DHT.h>
#include "DHT.h"
;


#define DHT2PIN 2     // what pin we're connected to


// Uncomment one of the lines below for whatever DHT sensor type you're using!
#define DHTTYPE DHT21   // DHT 21 (AM2301)
#define DHT2TYPE DHT22   // DHT 22  (AM2302), AM2321


DHT dht2(DHT2PIN, DHT2TYPE);

// IR Remote  

#define Relay_1 14
#define Relay_2 12
#define Relay_3 13

// WiFi network info.
char ssid[] = "earth9200";
char wifiPassword[] = "12345678";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "10da3140-178b-11eb-8779-7d56e82df461";
char password[] = "d6b7c0616f91f0d818b60592297fccd6834d520b";
char clientID[] = "28241290-894a-11eb-8779-7d56e82df461";

unsigned long lastMillis = 0;

void setup() {
 Serial.begin(9600);
 Cayenne.begin(username, password, clientID, ssid, wifiPassword);
 dht2.begin();
 pinMode(2, OUTPUT);
pinMode(Relay_1, OUTPUT);
pinMode(Relay_2, OUTPUT);
pinMode(Relay_3, INPUT);
digitalWrite(2,HIGH);
digitalWrite(Relay_1,HIGH);
digitalWrite(Relay_2,HIGH);

}

void loop() {
Cayenne.loop();
float h2 = dht2.readHumidity();
float t2 = dht2.readTemperature();



Cayenne.virtualWrite(3, t2, TYPE_TEMPERATURE, UNIT_CELSIUS);
Cayenne.virtualWrite(4, h2, TYPE_RELATIVE_HUMIDITY, UNIT_PERCENT);



 Serial.println ("Suhu DHT22");
 Serial.println(t2);
 Serial.println("Kelembaban DHT22");
 Serial.println(h2);

 Serial.println("===========================================");
 delay(20000);
}

// Default function for sending sensor data at intervals to Cayenne.
// You can also use functions for specific channels, e.g CAYENNE_OUT(1) for sending channel 1 data.
CAYENNE_OUT_DEFAULT()
{
  // Write data to Cayenne here. This example just sends the current uptime in milliseconds on virtual channel 0.
  //Cayenne.virtualWrite(0, millis());
  // Some examples of other functions you can use to send data.
  //Cayenne.celsiusWrite(1, 22.0);
  //Cayenne.luxWrite(2, 700);
  //Cayenne.virtualWrite(0, , TYPE_PROXIMITY, UNIT_CENTIMETER);
}

// Default function for processing actuator commands from the Cayenne Dashboard.
// You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.
CAYENNE_IN_DEFAULT()
{
  CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
  //Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}
