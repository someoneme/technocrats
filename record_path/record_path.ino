#include <string.h>
int r_clock=0;
int k=0;
int r_anticlock=0;
int l_clock=0;
int l_anticlock=0;
int pin_r_a=0;
int pin_r_b=0;
int pin_l_a=0;
int pin_l_b=0;
int last_stage_r;
int last_stage_l;
int state;
//String pos[500];
String record[100];
void setup(){
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT); 
  Serial.begin(9600);

  int pin_r_a = digitalRead(5);
  int pin_r_b = digitalRead(6);
  int pin_l_a = digitalRead(7);
  int pin_l_b = digitalRead(8);  
}

void loop(){
  pin_r_a = digitalRead(5);
  pin_r_b = digitalRead(6);
  pin_l_a = digitalRead(7);
  pin_l_b = digitalRead(8);
  int right_val=right()
}


char right(){
  if(pin_r_a!=last_stage_r){
    if(pin_r_b!=pin_r_a){
      r_clock++;
      last_stage_r = pin_r_a;
      return 1;
    } 
    else{
      r_anticlock++; 
      last_stage_r = pin_r_a;
      return 10;
    }
  }
  last_stage_r = pin_r_a; 
  return 100;
}


char left(){
  if(pin_l_a!=last_stage_l){
    if(pin_l_b!=pin_l_a){
      l_clock++;
      last_stage_l = pin_l_a;
      return 2;
    } 
    else{
      l_anticlock++; 
      last_stage_l = pin_l_a;
      return 20;
    }
  }
  last_stage_l = pin_l_a; 
  return 200;
}

char move(int a,int b,int last,int clock,int anticlock){
  if(a!=last)
    if(b!=a){
      clock++;
      last = a;
      return 2;
    } 
    else{
      anticlock++; 
      last = a;
      return 20;
    }
  }
  last = a; 
  return 200;
}

