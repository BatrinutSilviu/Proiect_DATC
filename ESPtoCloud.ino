#include "WiFi.h"
#include "HTTPClient.h"
#define RETRY_LIMIT  20
const char* ssid = "Silviu";
const char* password = "casino17";

void setup()
{
 
    Serial.begin(9600);
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
    int t=2;
    int h=3;
    //Open a connection to the server
    HTTPClient http;
    http.begin("http://192.168.1.101/EXPAI/Script2.php");
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    //format your POST request.
      int httpResponseCode = http.POST("temperature=" + String(t) +"& humidity=" + String(h));

      if (httpResponseCode >0){
          //check for a return code - This is more for debugging.
        String response = http.getString();
        Serial.println(httpResponseCode);
        Serial.println(response);
      }
      else{
        Serial.print("Error on sending post");
        Serial.println(httpResponseCode);
      }
    //closde the HTTP request.
      http.end();
  
    //Monitor values in console for debugging.
      Serial.println("Temp = " + String(t));
      Serial.println("humidity = " + String(h));
    
    
   //wait 2 minutes for next reading
    delay(120000);
    
    
}
