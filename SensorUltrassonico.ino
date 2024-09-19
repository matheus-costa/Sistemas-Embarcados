#define echo 31
#define trig 33

float tempo, distancia;

void setup(){
 Serial.begin(9600);
 pinMode(echo, INPUT);
 pinMode(trig, OUTPUT);

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
  delay(1000);
}