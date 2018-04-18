//define arduino pins for hcsr04 sensor
#define trigPin 2
#define echoPin 3

//define pin to trigger relay to turn on bulb
#define bulb 4

//define threshold distance to trigger the light on
int value,threshold=100;
bool check=false;

int calculate_distance(){
  int duration,distance;
  digitalWrite (trigPin, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin, LOW);
  duration = pulseIn (echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if(distance <= threshold){
     Serial.print("parked");  
  }else{
     Serial.print("unparked");  
  }
    
 return distance;
}


void setup()

{
Serial.begin (9600); //Start the serial monitor
pinMode(trigPin, OUTPUT); //set the trigpin to output
pinMode(echoPin, INPUT); //set the echopin to input
pinMode (bulb, OUTPUT); //set the bulb pin  to output

//INITIALIZE bulb off
digitalWrite(bulb,LOW);

}

void loop()

{

value=calculate_distance();

if(value < threshold && check==false)
{
    light();
    check=true;
}

else if(value < threshold && check==true)
{
  light_off();
  check=false;
}

delay(3000);

}

void light() //Start the Light subroutine

{ 
  digitalWrite(bulb, HIGH); //turn on the light
}

void light_off()
{
  
digitalWrite(bulb, LOW); //turn off the light
}

