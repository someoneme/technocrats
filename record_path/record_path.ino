#include <string.h>
int r_clock=0,r_anticlock=0;
int l_clock=0,l_anticlock=0;
int pin_r_a=0,pin_r_b=0;
int pin_l_a=0,pin_l_b=0;
int last_stage_r,last_stage_l;
void setup(){
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT); 
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  Serial.begin(9600);  
}

void loop(){
  pin_r_a = digitalRead(5);
  pin_r_b = digitalRead(6);
  pin_l_a = digitalRead(7);
  pin_l_b = digitalRead(8);
  int right_val=move(pin_r_a,pin_r_b,last_stage_r,r_clock,r_anticlock);
  int left_val=move(pin_l_a,pin_l_b,last_stage_l,l_clock,l_anticlock);
  if(right_val+left_val==0){
    Serial.println("Forward");
    reset();
  }
  else if(right_val+left_val==30){
    Serial.println("Right");
    reset();
  }
  else if (right_val+left_val==-30){
    Serial.println("left");
    reset();
  }
}

int move(int a,int b,int last,int clock,int anticlock){
  if(a!=last){
    if(b!=a){
      clock++;
      //last = a;
      //return 2;
    } 
    else{
      anticlock++; 
      //last = a;
      //return 20;
    }
  }
  last = a; 
  //return 200;
  if(clock==30)
    return clock;
  else if(anticlock==30)
    return -anticlock;
  else
    return 200;
}
void reset(){
  r_clock=0;
  r_anticlock=0;
  l_clock=0;
  l_anticlock=0;
}
