#define echo 31
#define trig 33
#define buzz 35

float tempo, distancia;

void setup(){
 Serial.begin(9600);
 pinMode(echo, INPUT);
 pinMode(trig, OUTPUT);
 pinMode(buzz, OUTPUT);

}
void loop(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  tempo = pulseIn(echo, HIGH);
  distancia = (tempo *0.0343)/2;
  Serial.println(distancia,4);

  if(distancia<10){
    tone(buzz,1000);
    delay(50);
    noTone(buzz);
    delay(50);
  }else if(distancia<25){
    tone(buzz,1000);
    delay(100);
    noTone(buzz);
    delay(100);
  }else if(distancia<50){
    tone(buzz,1000);
    delay(200);
    noTone(buzz);
    delay(200);
  }else if(distancia>50){
    delay(2000);
  }
/*tone(buzz, 1000);
  delay(100);
  noTone(buzz);*/

  //delay(1000);
}