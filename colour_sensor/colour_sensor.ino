long int time = 0;
int s0 = 6;
int s1 = 7;
int s2 = 8;
int s3 = 9;
int sensor = 10;
void setup(){
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT); 
  pinMode(sensor,INPUT); 
  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);
  Serial.begin(9600);
}

void loop(){
  col(0,1,"BLUE ");
  col(1,1,"GREEN ");
  col(0,0,"RED ");  
  Serial.println(" ");
  delay(3000);
}

void col(int a,int b,String s){
  digitalWrite(s2,a);
  digitalWrite(s3,b);
  time = pulseIn(sensor, HIGH);
  Serial.print(s);
  Serial.print(map(time,128,0,0,255));
  Serial.println("  ");

  delay(100);  
}

