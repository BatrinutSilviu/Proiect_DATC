#include "DHT.h"
#include "WiFi.h"
#include "HTTPClient.h"

#define RETRY_LIMIT  20
const char* ssid = "Silviu";
const char* password = "casino17";
DHT dht1(2, DHT11);

void setup()
{
    Serial.begin(9600);
    dht1.begin();
    WiFi.begin(ssid,password);
    while (WiFi.status()!= WL_CONNECTED){
      delay(500);
      Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP Address");
    Serial.println(WiFi.localIP());
 
}

void loop()
{
    int rtl = RETRY_LIMIT;
    delay(3000);
 
    float t = dht1.readTemperature();
    float h = dht1.readHumidity();
    Serial.print("DHT11  ");
    Serial.print(t,1); Serial.print(String(char(176))+"C  ");
    Serial.print(h,1); Serial.println("%RH");
    Serial.println();
    
    HTTPClient http;
    http.begin("http://192.168.1.102/EXPAI/Script2.php");
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpResponseCode = http.POST("temperature=" + String(t) +"& humidity=" + String(h));

      if (httpResponseCode >0){
        String response = http.getString();
        Serial.print("Sent with code ");
        Serial.println(httpResponseCode);
        Serial.println(response);
      }
      else{
        Serial.print("Error on sending post");
        Serial.println(httpResponseCode);
      }
      http.end();
  
      Serial.println("Temp = " + String(t));
      Serial.println("humidity = " + String(h));
    
    //delay(120000);
    delay(2000);
    
}
