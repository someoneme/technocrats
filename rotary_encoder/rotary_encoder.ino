int counter = 0;
int pin_a=0;
int pin_b=0;
int last_stage;
int state;
void setup(){
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT); 
  Serial.begin(9600);
 
  int pin_a = digitalRead(5);
  int pin_b = digitalRead(6);
}

void loop(){
  pin_a = digitalRead(5);
  pin_b = digitalRead(6);
  if(pin_a!=last_stage){
    if(pin_b!=pin_a){
      counter++;
    } 
    else{
      counter--; 
    }
    Serial.println(counter);
  }
 
  last_stage = pin_a;
}
