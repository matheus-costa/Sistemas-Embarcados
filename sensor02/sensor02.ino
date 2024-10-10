#define pinoSensor 31
#define pinoBuzzer 33

int estadoSensor;

void setup() {
 Serial.begin(9600);
 pinMode(pinoSensor,INPUT);
 pinMode(pinoBuzzer,OUTPUT);
}

void loop() {
  estadoSensor = digitalRead(pinoSensor);
  Serial.println(estadoSensor);
  if(estadoSensor){
    tone(pinoBuzzer, 1000);
    delay(500);
    noTone(pinoBuzzer);
  }
}