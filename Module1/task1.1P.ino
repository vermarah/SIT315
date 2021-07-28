// C++ code
//


const int motion_pin = 2;                //setting up the pins for the sensors
const int led_pin = 12;
const int buzz_pin = 7;

void setup()
{
   
  pinMode(led_pin, OUTPUT);            //setting up the output/input pins for the sensors
  pinMode(buzz_pin, OUTPUT);
  //pinMode(motion_pin, INPUT_PULLUP); 
   
  attachInterrupt(digitalPinToInterrupt(motion_pin), isr, CHANGE);  //change used for intrupting whenever the pin changes value
  Serial.begin(9600);
}

void loop()
{
  //nothing here
}

  

void isr()
{
  	if (digitalRead(motion_pin) == HIGH) //if motion is sensed, we see the led light and hear the buzzer 
    {
    									//turning the LED on and buzzer sounds
    digitalWrite(led_pin, HIGH);
    tone(buzz_pin, 100);
    Serial.println("Sensed the motion");
  }
  else 
  {
    digitalWrite(led_pin, LOW);     //if motion is not sensed, we turn off the led light and the buzzer 
    noTone(buzz_pin);
    Serial.println("Nothing there");   //output on the serial monitor
  }

}

