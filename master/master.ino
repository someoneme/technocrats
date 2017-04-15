int a_start = 0;
int a_stop = 0;
int a_right = 0;
int a_left = 0;
void setup(){
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
}
void loop(){
  a_start = Serial.read();    
  a_stop = Serial.read();
  a_right = Serial.read();
  a_left = Serial.read();
  move(a_start,a_stop,a_right,a_left);
}
void move(int start,int stop,int right,int left){
       digitalWrite(6, right*start*(1-stop));
       digitalWrite(7, left*start*(1-stop));
}
