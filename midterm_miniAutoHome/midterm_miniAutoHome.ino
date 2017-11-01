
/*  PulseSensor™ Starter Project   http://www.pulsesensor.com
 *   
This an Arduino project. It's Best Way to Get Started with your PulseSensor™ & Arduino. 
-------------------------------------------------------------
1) This shows a live human Heartbeat Pulse. 
2) Live visualization in Arduino's Cool "Serial Plotter".
3) Blink an LED on each Heartbeat.
4) This is the direct Pulse Sensor's Signal.  
5) A great first-step in troubleshooting your circuit and connections. 
6) "Human-readable" code that is newbie friendly." 
*/


//  Variables

#include <MsTimer2.h>               //定时器库的 头文件
#include <Servo.h>

Servo myservo;

int PulseSensorPurplePin = 0;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
int LED13 = 13;   //  The on-board Arduion LED
int LED12 = 12;
int LED11 = 11;

int Signal;    // holds the incoming raw data. Signal value can range from 0-1024
int foreSignal;
int Threshold = 550; // Determine which Signal to "count as a beat", and which to ingore. 
int count=0;
int night=1;

// The SetUp Function:
void setup() {
  pinMode(LED13,OUTPUT);         // pin that will blink to your heartbeat!
  pinMode(LED12,OUTPUT);
  pinMode(LED11,OUTPUT);

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  
   Serial.begin(9600);         // Set's up Serial Communication at certain speed. 
   MsTimer2::set(6000, detect);        // 中断设置函数，每 6s 进入一次中断
   MsTimer2::start();    
}

void whetherNight(){
  if(night==1){
    digitalWrite(LED11,HIGH); 
    digitalWrite(LED12,HIGH); 
    }
  else{
    digitalWrite(LED11,LOW); 
    digitalWrite(LED12,LOW); 
    }
  }

  
void detect(){
  if(count<25)
  {
    night=1;
    myservo.write(20);
    }
    else{
      night=0;
      myservo.write(90);
      }

     count=0;
  }
  

// The Main Loop Function
void loop() {
  foreSignal=Signal;
  Signal = analogRead(PulseSensorPurplePin);  // Read the PulseSensor's value. 
                                              // Assign this value to the "Signal" variable.

   Serial.println(Signal);                    // Send the Signal value to Serial Plotter.

   
   if(Signal > Threshold){                          // If the signal is above "550", then "turn-on" Arduino's on-Board LED.  
     digitalWrite(LED13,HIGH);     
   } else {
     digitalWrite(LED13,LOW);                //  Else, the sigal must be below "550", so "turn-off" this LED.
   }

   if((foreSignal<550)&&Signal>600){
      count++;
      Serial.print("count=");
      Serial.println(count);
    }
    whetherNight();


delay(10);
   
   
}
