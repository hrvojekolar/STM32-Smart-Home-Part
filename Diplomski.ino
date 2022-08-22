#include <LiquidCrystal.h>

#include <DHT.h>
#include <Wire.h>

const int rs = PB11, en = PB10, d4 = PB0, d5 = PB1, d6 = PC13, d7 = PC14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define DHTPIN PA1
#define DHTTYPE DHT11
#define BULB_BTN PB9
#define BULB PB8
#define MOTOR_DOWN PB3
#define MOTOR_UP PB4
#define SENSOR_DOWN PB5
#define SENSOR_UP PB6
 
DHT dht(DHTPIN, DHTTYPE);  

int ledflag=0;
int previousTime=0;
int currentTime=0;

void setup() {
dht.begin(); 
Serial1.begin(9600);
lcd.begin(16,2);
lcd.print("Powering on...");
delay(3000);
lcd.clear();
pinMode(BULB_BTN,INPUT);
pinMode(BULB,OUTPUT);
digitalWrite(BULB,LOW);

pinMode(MOTOR_DOWN,INPUT);
pinMode(MOTOR_UP,INPUT);
pinMode(SENSOR_DOWN,INPUT);
pinMode(SENSOR_UP,INPUT);
pinMode(MOTOR,OUTPUT);

}

void loop() {
float humidity = dht.readHumidity();     
float temperature = dht.readTemperature(); 

if(MOTOR_UP == HIGH && SENSOR_UP = LOW){
  MOTOR == HIGH;
}

if(MOTOR_DOWN == HIGH && SENSOR_DOWN = LOW){
  MOTOR == HIGH;
}

if(digitalRead(BULB_BTN)==HIGH){
  if(ledflag == 0){
    ledflag = 1;
    digitalWrite(BULB,HIGH);
  }
  else{
    ledflag=0;
    digitalWrite(BULB,LOW);
  }
}
if(millis()-previousTime > 5000){
  previousTime=millis();
  lcd.clear();
}

lcd.setCursor(0,0);
lcd.print("Vlaga : ");
lcd.print(humidity);
lcd.print(" %");
lcd.setCursor(0,1);
lcd.print("Temp : ");
lcd.print(temperature);
lcd.print(" C");

}
