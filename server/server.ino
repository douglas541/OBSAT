#include <SPI.h>
#include <WiFi.h>

char* ssidESP = "wifitest";                        // SSID of your ESP Server
char* passESP = "wifitest";                        // password of your ESP Server

WiFiServer server(80);

  IPAddress ip(192, 168, 10, 40);            // IP address of the server
  IPAddress gateway(192, 168, 10, 1);        // gateway of the server
  IPAddress subnet(255, 255, 255, 0);        // subnet mask of the server

void setup() {
  Serial.begin(115200);                      // Only for debug
  
  WiFi.mode(WIFI_AP_STA);                    // Need both to serve the webpage and take commands via tcp

  WiFi.softAPConfig(ip, gateway, subnet);
  WiFi.softAP(ssid, pass);                   // Access point password and identification
  delay(500);
  Serial.print("AP IP address: ");
  Serial.println(ip);
  server.begin();                            // Starts the server

  Serial.println("Server Started");
  Serial.print("IP: ");       Serial.println(WiFi.softAPIP());
  Serial.print("SSID: ");     Serial.println(WiFi.SSID());
  Serial.print("Signal: ");   Serial.println(WiFi.RSSI());
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  String request = client.readStringUntil('\r');
  client.flush();

  if (request == "connected") {
    Serial.print("Data Received: "); Serial.println(request);
    delay(200);
  }
  delay(200);
}
