#include <TM1637Display.h> //adicionando uma biblioteca

#define clk 31
#define dio 33

TM1637Display display = TM1637Display(clk, dio);

const uint8_t allON[] = {0xff, 0xff, 0xff, 0xff}; 
const uint8_t allOFF[] = {0x00, 0x00, 0x00, 0x00}; 

const uint8_t cafe[]{
  SEG_A | SEG_D | SEG_E | SEG_F,                //C
  SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G,//A
  SEG_A | SEG_E | SEG_F | SEG_G,                //F
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G         //E
};
void setup(){

}
void loop(){
  display.setBrightness(7);
  int i;
  for(i=0; i<100; i++){
    display.showNumberDec(i);
    delay(1000);
  }
  /*display.setSegments(cafe);
  delay(2000);
  display.clear();//PISCANDO CAFÉ
  delay(2000);*/

  /*display.setBrightness(0);
  display.setSegments(allON);
  delay(2000);//BRILHO MÍNIMO E BRILHO MÁXIMO
  display.setBrightness(7);
  display.setSegments(allON);
  delay(2000);*/
}
