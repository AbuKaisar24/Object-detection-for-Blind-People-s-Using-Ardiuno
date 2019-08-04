#define tripin1 13
#define echopin1 12
#define tripin2  11
#define echopin2  10
void setup()
{
  Serial.begin(9600);
  pinMode(tripin1,OUTPUT);
  pinMode(echopin1,INPUT);
  pinMode(tripin2,OUTPUT);
  pinMode(echopin2,INPUT);
  pinMode(8,OUTPUT);
}
void loop()
{
  long distance1,duration1,distance2,duration2;
  digitalWrite(tripin1, LOW);
  delayMicroseconds(2);
  digitalWrite(tripin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(tripin1, LOW);
  duration1 = pulseIn(echopin1, HIGH);
  distance1 = (duration1/2) / 29.1;
  
  digitalWrite(tripin2, LOW);
  delayMicroseconds(2);
  digitalWrite(tripin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(tripin2, LOW);
  duration2 = pulseIn(echopin2, HIGH);
  distance2 = (duration2/2) / 29.1;
  int total= distance1+distance2;
  if (total >= 100 || total <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.println(String(total)+"cm from eyes \t");
    tone(9, 1000, 1000);
    digitalWrite(8,HIGH);
    delay(1000);
  }
  delay(500);
}
