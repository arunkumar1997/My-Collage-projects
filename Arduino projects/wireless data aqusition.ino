#include <dht.h>
#include <SoftwareSerial.h>

dht DHT;
SoftwareSerial BT (10,9);//tx,rx

int s_val;
int r = 0;
int a = 0;

void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(2,OUTPUT);//triger pin
  pinMode(3,INPUT); // echopin
  pinMode(4,INPUT);//  ldr pin
  pinMode(A0,INPUT);// rain 
  pinMode(A1,INPUT);//water detect
  pinMode(A2,INPUT);//smoke
  pinMode(5,INPUT);//humidity
  Serial.println("Waiting for you command!!");
  BT.println("Waiting for you command!!");
  delay(800);
  BT.println("\n1] Ultrasonic\n2 LDR\n3] Rain\n4] Water\n5] Smoke\n6] Humidity and Temp\n");
  Serial.println("\n1] Ultrasonic\n2] LDR\n3] Rain\n4] Water\n5] Smoke\n6] Humidity and Temp\n");




}
void option(){
  BT.println("\n1] Ultrasonic\n2] LDR\n3] Rain\n4] Water\n5] Smoke\n6] Humidity and Temp\n");
  Serial.println("\n1] Ultrasonic\n2] LDR\n3] Rain\n4] Water\n5] Smoke\n6] Humidity and Temp\n");
}
//Ultrasinic
void ultrasonic(){
  a = 0;
   BT.println("----Ultrasonic----");
   Serial.println("----Ultrasonic----");
      while(a<=5){
        digitalWrite(2,LOW);
        delayMicroseconds(2);
        digitalWrite(2,HIGH);
        delayMicroseconds(10);
        digitalWrite(2,LOW);
        const unsigned long duration = pulseIn(3,HIGH);
        int distance = (duration/2)/29.1;        
        Serial.print("distance:");
        Serial.print(distance);
        Serial.println("cm");
        BT.println(String(distance));
        delay(1000);
        a = a+1;
      }
}
//LDR
void LDR(){
  a=0;
  BT.println("----LDR----");
  Serial.println("----LDR----");
  while(a<=5){
    r = digitalRead(4);
    Serial.println(r);
    BT.println(r);
    delay(1000);
    a = a+1;
  }
}

//Rain
void rain(){
  a = 0;
  r = 0;
  BT.println("----Rain----");
  Serial.println("----Rain----");
    while(a<=5){
    r = analogRead(A0);      
    Serial.print(r);
    Serial.println("Rain");
    BT.println(r);
    delay(1000);
    a = a+1;
    }
}
//water detect
void water(){
  a = 0;
  r = 0;
  BT.println("----Water----");
  Serial.println("----Water----");
    while(a<=5){
    r = analogRead(A0);
    Serial.print(r);
    Serial.println("Water");
    BT.println(r);
    delay(1000);
    a = a+1;
    }
}
//smoke
void smoke(){
  a = 0;
  r = 0; 
  BT.println("----Smoke----");
  Serial.println("----Smoke----");
    while(a<=5){
     r  = analogRead(A2);
      if(r>400){
        Serial.print(r);
        Serial.println("Smoke");
        BT.println(r);
        delay(1000);
        a = a+1;
      }
      else{
        Serial.print(r);
        Serial.println("No Smoke");
        BT.println(r);
        delay(1000);
        a = a+1;
      }
    }
}
//humidity
void humidity(){
  a = 0;
  r = 0;
  BT.println("----Humidity and Temp----");
  Serial.println("----Humidity and Temp----");
    while(a<=5){
    r = DHT.read11(5);
    Serial.print(DHT.temperature );
    Serial.println("Temp");
    BT.println(DHT.temperature);
    Serial.print(DHT.humidity);
    Serial.println("Humidity");
    BT.println(DHT.humidity);
    
    delay(1000);
    a = a+1;
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  while(BT.available() || Serial.available()){
    delay(500);
    s_val = BT.read();
    BT.println(s_val);
    if(s_val == '1'){
        ultrasonic();
         delay(1000);
        option();
      }
    else if (s_val == '2'){
        LDR();
        delay(1000);
        option();
    }
    else if (s_val == '3'){
      rain();
       delay(1000);
        option();
    }
    else if (s_val == '4'){
      water();
       delay(1000);
        option();
    }
    else if (s_val == '5'){
      smoke();
       delay(1000);
        option();
    }
    else if (s_val =='6'){
      humidity();
       delay(1000);
        option();
    }
  }
}
