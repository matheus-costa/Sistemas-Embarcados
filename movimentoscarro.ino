  #include <SoftwareSerial.h>

  SoftwareSerial hc06(50,51);
  
  void frente(int vel);
  void tras(int vel);
  void esquerdaF(int vel);
  void esquerdaT(int vel);
  void direitaF(int vel);
  void direitaF(int vel);
  void parado();

  //MOTORES ESQUERDOS
  int i1 = 2;
  int i2 = 3;
  //MOTORES DIREITOS
  int i3 = 4;
  int i4 = 5;

  int encho = 31;
  int trig = 33;

  int dir;
  int ultDir = 'F';
  float tempo, distancia;
  int vel;

  void setup(){
    Serial.begin(9600);
    hc06.begin(9600);
    vel=130;
    pinMode(echo,INPUT);
    pinMode(trig,OUTPUT);
    pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
    pinMode(in3,OUTPUT);
    pinMode(in4,OUTPUT);
  }
   
  void loop(){
    digitalWrite(trig,LOW);
    delayMicrosecoinds(2);
    digitalWrite(trig,HIGH);
    delayMicrosecoinds(10);
    digitalWrite(trig,LOW);

    tempo = pulseIn(encho,HIGH);
    distancia = (tempo*0.343)/2;

    delay(100);

    if(distancia<20){
      parado();
      delay(500);
      tras(vel);
      delay(500);
      parado();
      ultDir = 'T';
    }
    if(hc06.available()){
      dir = hc06.read();

      Serial.print("Direção atual:");
      Serial.print(dir);
      Serial.print("Direção anterior: ");
      Serial.print(dir);
    }

    if(dir=='F'){
      frente(vel);
      ultDir = dir;
    }
    if(dir=='T'){
      tras(vel);
      ultDir = dir;
    }
    if(dir=='E' && ultDir=='F'){
      esquerdaF(vel);

    }
    if(dir=='E' && ultDir=='T'){
      esquerdaT(vel);

    }
    
    if(dir=='D' && ultDir=='F'){
      direitaF(vel);
    }
    if(dir=='P'){
      parado();
      ultDir='F';
    }

  }

}  

void frente(int vel){
  analogWrite(in1,vel);
  analogWrite(in2,0);
  analogWrite(in3,vel);
  analogWrite(in4,0);
}

void tras(int vel){
  
  analogWrite(in1,0);
  analogWrite(in2,vel);
  analogWrite(in3,0);
  analogWrite(in4,vel);
}


void direitaF(int vel){
  
  analogWrite(in1,vel);
  analogWrite(in2,0);
  analogWrite(in3,0);
  analogWrite(in4,0);
}

void direitaT(int vel){
  
  analogWrite(in1,0);
  analogWrite(in2,vel);
  analogWrite(in3,0);
  analogWrite(in4,0);
}

void esquerdaF(int vel){
  
  analogWrite(in1,0);
  analogWrite(in2,0);
  analogWrite(in3,vel);
  analogWrite(in4,0);
}

void esquerdaT(int vel){
  
  analogWrite(in1,0);
  analogWrite(in2,0);
  analogWrite(in3,0);
  analogWrite(in4,vel);
}

void parado(int vel){
  
  analogWrite(in1,0);
  analogWrite(in2,0);
  analogWrite(in3,0);
  analogWrite(in4,0);
}




















