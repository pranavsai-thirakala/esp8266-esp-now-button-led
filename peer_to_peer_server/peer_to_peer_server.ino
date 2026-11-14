#include <ESP8266WiFi.h>
#include <espnow.h>
uint8_t broadcastAddress[] = {0xC4 ,0xD8 ,0xD5 ,0x26 ,0xC4 ,0x73};  // MAC address of the receiver NodeMCU

const int buttonPin = D4; 
// const int b=D8; // Pin where the button is connected
void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // Configure the button pin
    pinMode(b, INPUT_PULLUP);  // Configure the button pin

  Serial.begin(115200);  

  
  WiFi.mode(WIFI_STA);
  
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}
void loop() {
  int buttonState = digitalRead(buttonPin);
   


  String message;
  if (buttonState == LOW) {  // Button pressed (assuming active-low)
    message = "LED_ON";
  } else {
    message = "LED_OFF";
  }
  esp_now_send(broadcastAddress, (uint8_t *)message.c_str(), message.length());
  delay(500);  // Debounce delay
}
