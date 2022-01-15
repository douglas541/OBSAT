#include <WiFi.h>

char ssid[] = "wifitest";                                 // SSID of your ESP Server
char pass[] = "wifitest";                                 // password of your ESP SEVER
  
IPAddress server(192,168,10,40);                      // the fix IP address of the server
WiFiClient client;

void setup() {
  Serial.begin(115200);                                // only for debug
  Serial.println("");
  Serial.print("Awaiting connection: ");
  WiFi.begin(ssid, pass);                              // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("Client Connected");
  Serial.print("SSID: ");     Serial.println(WiFi.SSID());
  Serial.print("Signal: ");   Serial.println(WiFi.RSSI());
}

void loop() {
  client.connect(server, 80);

  client.print("connected\r");
  delay(200);
}
