// C++ code
//


const int pingPin = 2;                //setting up the pins for the sensors
const int led_pin = 13;
const int buzz_pin = 7;

void setup()
{
  
  pinMode(led_pin, OUTPUT);            //setting up the output/input pins for the sensors
  pinMode(buzz_pin, OUTPUT);
  Serial.begin(9600);                  
}

void loop()
{
  										 //in inches and centimeters
  long duration, inches, cm;             //variables for distance and duration for conversion to microseconds
  
  
  pinMode(pingPin, OUTPUT);               // for getting a clean high pulse, gave a short LOW pulse beforehand
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);            //similarly repeating the process again
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  
  inches = microsecondsToInches(duration);              //converting the time into distance
  cm = microsecondsToCentimeters(duration);  
  
  if (cm <= 80)                      //conditional statement as if the cm distance is less than 80, the buzzer should sound
  {
    digitalWrite(led_pin, HIGH);     //and the led glows
    delay(500);
    digitalWrite(led_pin, LOW);
    delay(500);
    
    tone(buzz_pin, 1000);            //buzzer sounds
  }
  else                               //else condition
  {
    digitalWrite(led_pin, LOW);
    noTone(buzz_pin);
  }

  Serial.print(inches);             //printing the values on the serial monitor
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
}

long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet, there are 73.746 microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 29 microseconds per centimeter divide by 2 as back and forth
  return microseconds / 29 / 2;
}
