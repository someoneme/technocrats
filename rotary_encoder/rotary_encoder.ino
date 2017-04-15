int counter = 0;
int pin_a=0;
int pin_b=0;
void setup(){
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);  
  Serial.begin(9600);
  
  int pin_a = digitalRead(5);
  int pin_b = digitalRead(6);
}

void loop(){
  if((pin_a==1)&&(pin_b==1)){
    counter++;  
  }  
  if((pin_a==0)&&(pin_b==0)){
    counter++;
  }
  
  if(counter==15 ){
    Serial.println("yes");
  }
}

