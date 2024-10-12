#include <SoftwareSerial.h>

SoftwareSerial hc06(50,51);

int comando;
int pinoLED = 13;

void setup(){
   Serial.begin(9600);
   hc06.begin(9600);
   pinMode(pinoLED, OUTPUT);

}

void loop(){
   if(hc06.available()){
    comando = hc06.read();
     Serial.println(comando);
     delay(100);
     if(comando == 'L'){
      digitalWrite(pinoLED, HIGH);
     }
     if(comando == 'D'){
            digitalWrite(pinoLED, LOW);
     }
   }
}