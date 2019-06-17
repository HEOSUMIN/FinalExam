#include <SoftwareSerial.h>
SoftwareSerial BTSerial(11, 12);
int led = 2;
int buzzer=3;
int fire = A0;
int motor1 =6;
int motor2=7;
int value_previous, value_current;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
  value_previous = analogRead(fire);
  sendData(value_previous);
  pinMode(led,OUTPUT);
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(buzzer,OUTPUT);
}

void sendData(int value){
  String message = String(value) + '\n';
  BTSerial.print(message);
}

void loop() {
  if(BTSerial.available()){
    byte data =BTSerial.read();
    if(data=='1'){
      digitalWrite(motor1,LOW);
     digitalWrite(motor2,HIGH);
    
    }
    if(data=='2'){
       digitalWrite(motor1,LOW);
     digitalWrite(motor2,LOW);
   
    }
  } 

  
  value_current = analogRead(fire);
  int val = analogRead(fire);
  Serial.println(val);
  if(val < 800){
    digitalWrite(led,HIGH);
    tone(buzzer,255);
  }else{
    digitalWrite(led,LOW);
    noTone(buzzer);
  }

  if(value_current != value_previous){
    value_previous = value_current;
    sendData(value_current);
  }

  delay(1000);
}
