#include <ESP8266WiFi.h>
#include <espnow.h>
// #include<Servo.h>
// Servo servo ;

const int ledPin = D2;
// const int in1=D5;
// const int in2=D6;
// const int in3=D7;
// const int in4=D8;  // Pin where the LED is connected
void setup() {
  // servo.attach(D4);
  pinMode(ledPin, OUTPUT);  // Configure the LED pin
  digitalWrite(ledPin, LOW); 
  // // Ensure LED is initially off
  // pinMode(in1,OUTPUT);
  //   pinMode(in2,OUTPUT);

  // pinMode(in3,OUTPUT);
  // pinMode(in4,OUTPUT);


  
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);
}
void OnDataRecv(uint8_t *mac, uint8_t *incomingData, uint8_t len) {
  String receivedMessage = String((char*)incomingData);
  
  Serial.print("Received message: ");
  Serial.println(receivedMessage);
  
  if (receivedMessage == "LED_ON") {
    digitalWrite(ledPin, HIGH); 
    // servo.write(0);

    // Turn LED on
        //   digitalWrite(in1, HIGH);                                                        
        // digitalWrite(in2, LOW); 
   


  } else if (receivedMessage == "LED_OFF") {
    digitalWrite(ledPin, LOW);
    // servo.write(90);
  //        digitalWrite(in1, LOW);  
  //  digitalWrite(in2,LOW); 
  // // Turn LED off
  }
}
void loop() {
  // Nothing needed here
}
