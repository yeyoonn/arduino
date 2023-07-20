  int redPin = 3;
  int greenPin = 5;
  int bluePin = 9;
void setup()
    {pinMode(redPin, OUTPUT);
     pinMode(greenPin, OUTPUT);
     pinMode(bluePin, OUTPUT);
    }
// the loop function runs over and over again forever
void loop()
    {setColor(255, 0, 0); delay(1000);//red
     setColor(0, 255, 0); delay(1000);//green
     setColor(0, 0, 255); delay(1000);//blue
    }

void setColor(int red, int green, int blue)
    {analogWrite(redPin, red);
     analogWrite(greenPin, green);  
     analogWrite(bluePin, blue);    
    }  
