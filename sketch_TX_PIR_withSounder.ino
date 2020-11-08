#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int redLED = 9;
int greenLED = 8;
const int PIR_sensor_PIN = 10; 
#define Do 131
#define Re 147
#define Mi 165
const int spkPin = 7;
int solfege[] = {Do,Re,Mi};
int PIR_sensor_PIN_state=0;

void setup()
{
lcd.begin(16,2);
Serial.begin(9600);
pinMode(PIR_sensor_PIN, INPUT);
pinMode(redLED, OUTPUT);
pinMode(greenLED, OUTPUT);
lcd.setCursor(0,0);
lcd.print("SECURITY SYSTEM");
lcd.setCursor(0,1);
lcd.print("OF RESTRICTED AREA");
delay(500);
}

// the loop routine runs over and over again forever:
void loop() 
{
PIR_sensor_PIN_state = digitalRead(PIR_sensor_PIN);
if(PIR_sensor_PIN_state == HIGH)
{ 
    lcd.clear();      
    int PIR_SERIAL_BYTE=10;
    Serial.write(PIR_SERIAL_BYTE); 
    lcd.setCursor(0,1);
    lcd.print("SECURITY BREAK");
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    for(int i=0;i<8;i++)
      {
        tone(spkPin,solfege[i],1000);
        delay(50);
        return spkPin;
      }
} 
else
{
    lcd.clear();   
    int PIR_SERIAL_BYTE=20;
    Serial.write(PIR_SERIAL_BYTE); 
    lcd.setCursor(0,1);
    lcd.print("SYSTEM SECURED");
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    delay(50);
}
}
