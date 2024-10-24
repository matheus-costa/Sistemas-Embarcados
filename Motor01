#define in1 3
#define in2 5
#define in3 6
#define in4 9

int pwm;

void setup(){
     Serial.begin(9600);
     pinMode(in1, OUTPUT);
     pinMode(in2, OUTPUT);
     pinMode(in3, OUTPUT);
     pinMode(in4, OUTPUT);
}

void loop(){
  for( pwm = 0; pwm <255; pwm++){
    analogWrite(in1,pwm);
    analogWrite(in2,0);
    analogWrite(in3,pwm);
    analogWrite(in4,0);
    Serial.println(pwm);
    delay(50);
  }
  /*
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);*/
}
