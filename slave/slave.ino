int a_start = 0;
int a_stop = 0;
int a_right = 0;
int a_left = 0;
int motor_l = 9;
int motor_r = 10;
void setup(){
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
     Serial.begin(9600);
}
void loop(){
  a_start = analogRead(4);
  a_stop = analogRead(5);
  a_right = analogRead(6);
  a_left = analogRead(7);
  move(a_start,a_stop,a_right,a_left);
}
void move(int start,int stop,int right,int left){
   digitalWrite(motor_r, right*start*(1-stop));
   digitalWrite(motor_l, left*start*(1-stop));
} 
