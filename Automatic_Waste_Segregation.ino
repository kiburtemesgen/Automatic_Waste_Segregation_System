#include <Servo.h>
#define SensorPin A3
int IRpin=7;
int IRValue=1;
float sensorValue = 0;
Servo myservo;
Servo myservo1;
int servoState=0;
int servoState2=0;
int switchPin=12;
int switchValue;

//////////////METAL DETCTOR////
float metalDetected;
int monitoring;
int metalDetection=1;

void setup() {
   pinMode(switchPin,INPUT_PULLUP);
  myservo.attach(9); 
  myservo1.attach(10);
  pinMode(IRpin,INPUT);
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
switchValue= digitalRead(switchPin);
Serial.println("switch state");
Serial.println(switchValue);
//delay(200);
for(int i=0; i<=100; i++)
{
  sensorValue=sensorValue + analogRead(SensorPin);
  delay(1);
  }
sensorValue=sensorValue/100.0;
Serial.println("Miost value:");
Serial.println(sensorValue);
delay(30);
Serial.print("servoState:");
delay(100);
Serial.println(servoState);
Serial.print("servoState2:");
delay(100);
Serial.println(servoState2);
delay(100);
///////IR SENSOR//////
IRValue=digitalRead(IRpin);
Serial.print("IR value:");
Serial.println(IRValue);
//if(IRValue==0){
  //Serial.println("waste detected");
  
  //}
  ////////////METAL DETCTOR LOOP///////
monitoring=analogRead(metalDetection);
  metalDetected= (float) monitoring*100/1024.0;
  Serial.print("metal value is");
  Serial.println(metalDetected);
  delay(100);
/////////////////////////

if(sensorValue<1000 && servoState==0 && servoState2==0 ){
  Serial.println("................................................wet waste detected");
  myservo.write(-90);
  delay(1000);
  myservo1.write(90);
  delay(1000);
  servoState=1;
  servoState2=0;
  }
  else if((metalDetected>10)  && (servoState2==0) && (servoState==0) ){
    Serial.println("............................................metal detected");
    myservo1.write(180);
    delay(1000);
    //myservo.write(-90);
    //delay(1000);
    servoState=0;
    servoState2=1;
    
    }
  else if((sensorValue<1000) &&  (servoState==0) && (servoState2==1)  )
  {
     
   myservo1.write(90);
    delay(1000);
    myservo.write(0);
    delay(1000);
    
    servoState=1;
    servoState2=0;
    Serial.println("....................................condition3");
    }
    else if((metalDetected>10) && (servoState2==0) && (servoState==1) )
  {
     Serial.println("....................................condition4");
   myservo.write(90);
    delay(1000);
    myservo1.write(180);
    delay(1000);
     
    servoState=0;
    servoState2=1;
    } 
  //  else if(sensorValue<1000 && servoState==1 && servoState2==0  )
  //{
    // Serial.println(".................................condition5");
    //myservo.write(-90);
   // delay(1000);
    //myservo1.write(90);
    //delay(1000);
    //servoState=1;
    //servoState2=0;
    
   // }
    
 // else if((metalDetected>10) && (servoState2==1) && (servoState==0) )
  //{
    // Serial.println(".......................................condition6");
   // myservo1.write(0);
    //delay(500);
    //myservo1.write(180);
    //delay(500);
    // servoState=0;
    //servoState2=1;
 
//    } 

   // else if(sensorValue>1000 && metalDetected<10 && servoState==0 && servoState2==0){
     // servoState=0;
       //servoState2=0;
       //Serial.println("............................................condition7");
      //}
    else if((sensorValue>1000) && (metalDetected<10) && (servoState==1)   && (IRValue==0) && (servoState2==0))
    {
      myservo.write(90);
      delay(1000);
      myservo1.write(90);
      delay(1000);
      servoState=0;
      servoState2=0;
      Serial.println("............................................condition8");
      }
      else if((sensorValue>1000) && (metalDetected<10) && (servoState2==1)  &&(servoState==0) && (IRValue==0)){
    //  myservo.write(0);
      //delay(1000);
      myservo1.write(90);
      delay(1000);
      servoState=0;
      servoState2=0;
      Serial.println("............................................condition9");
      }
delay(250);

}
