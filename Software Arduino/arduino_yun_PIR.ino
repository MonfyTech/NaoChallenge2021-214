#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>
#include <string.h>

#define LED       13    // Pin Led
#define PIR        8    // Pin PIR
#define PORT    7891    // Port for connection
int PIRstate = LOW;     // state of the PIR sensor
char echo_message[50];  // buffer

YunServer server(PORT);
bool flag;
void setup() {
  pinMode(PIR, INPUT)
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Ready");
  Bridge.begin();
  Serial.println("Bridge started");
  server.noListenOnLocalhost();
  server.begin();
}

void loop() {
  Serial.println("Waiting server");         // for debug
  char echo_message[50];                    // buffer
  YunClient client = server.accept();
  if (client.connected())
  {
    digitalWrite(LED,LOW); 
    Serial.println("Connected!");           // for debug
    Serial.println("Ready!");
    client.print("Client Ready!");
    while (client.connected())
    {
      int valPIR = digitalRead(PIR);
      if(valPIR==HIGH)
      {
        digitalWrite(LED,HIGH);
        if (PIRstate == LOW) 
        {
          PIRstate = HIGH;
          client.print(String("MOVIMENTO RILEVATO")); 
          Serial.println("Movimento rilevato!");
        }    
      }
      else
      {
        digitalWrite(LED, LOW);
        if (PIRstate == HIGH) 
        { 
          PIRstate = LOW;
          client.print(String("MOVIMENTO TERMINATO"));
          Serial.println("Movimento terminato!");
        }    
      }
    } 
    client.stop();              // Disconnects from the server
    Serial.println("pronto!");  // Client disconnected
    digitalWrite(LED,LOW); 
  }
  else
    Serial.println("\tNo client connected");      // for debug
  delay(150);
}




