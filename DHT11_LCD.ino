#include <SimpleDHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display
// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

void setup() {
  Serial.begin(115200);
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  lcd.setCursor(2,1);
  lcd.print("Myeungmun !");

}

void loop() {
  lcd.init();
  // Print a message to the LCD.
  //lcd.backlight();  
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
int t=temperature;
  lcd.init();
  lcd.init();
  lcd.clear();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("TEMP - ");
  lcd.setCursor(7,0);
  lcd.print(t);
  lcd.setCursor(9,0);
  lcd.write(223);
  lcd.setCursor(10,0);
  lcd.println("C");
 lcd.setCursor(11,0);
  lcd.println("    ");
  lcd.setCursor(0,1);
  lcd.print("Humi = ");
  lcd.setCursor(7,1);
  lcd.println(humidity);
  lcd.setCursor(11,1);
  lcd.print("%");
  // DHT11 sampling rate is 1HZ.
  delay(1500);
}
