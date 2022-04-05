
#include <LiquidCrystal.h>

LiquidCrystal_
LiquidCrystal lcd(2,3,4,5,6,7);
int in=8;
int out=9;
int led=10;
int c=0;
int Contrast=100;
void setup() {
  // put your setup code here, to run once:
    analogWrite(11,Contrast);
    lcd.begin(16,2);
    lcd.print("Visitor Counter");
    delay(5000);
    pinMode(in,INPUT);
    pinMode(out,INPUT);
    pinMode(led,OUTPUT);
    lcd.clear();
    lcd.print("Person In Room");
    lcd.setCursor(0,1);
    lcd.print(c);
    
}

void loop() {
  // put your main code here, to run repeatedly:
   int inval=digitalRead(in);
   int outval=digitalRead(out);
   if(inval==LOW)
   {
    c++;
    lcd.clear();
    lcd.print("Person In Room");
    lcd.setCursor(0,1);
    lcd.print(c);
    delay(1000);
    
   }
   if(c>0)
   {
   if(outval==LOW)
   {
    c--;
    lcd.clear();
    lcd.print("Person In Room");
    lcd.setCursor(0,1);
    if(c>=0)
    lcd.print(c);
    delay(1000);
    
   }
   }
   
   if(c<=0)
   {
    c=0;
    lcd.clear();
    digitalWrite(led,LOW);
    lcd.print("Nobody In Room");
    lcd.setCursor(0,1);
    lcd.print("Light Is Off");
    delay(100);
   }
   else
   {
    digitalWrite(led,HIGH);
   }
}
