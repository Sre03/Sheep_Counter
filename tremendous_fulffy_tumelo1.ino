int trig1 = 12, echo1 = 9;
int trig2 = 6, echo2 = 3;
int c = 0;
int pc = 0;
void setup(){
  pinMode(trig1, OUTPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  Serial.begin(9600);
}
void loop(){
  float time1, time2, dist1, dist2;
  float gate = 150;
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, LOW);
  delayMicroseconds(2); 
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);  
  time1 = pulseIn(echo1, HIGH);  
  dist1 = 0.034*(time1/2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);  
  time2 = pulseIn(echo2, HIGH);  
  dist2 = 0.034*(time2/2);
  if(dist1<gate){
    c++;
    delay(700); 
  }
  if(dist2<gate){
    if(c>0){
      c--;
      delay(700);
    }  	
  }
  if (pc!=c){    
  Serial.print("Number of Sheeps Inside : ");
  Serial.println(c);
  pc=c;
  }
  delay(500);
}