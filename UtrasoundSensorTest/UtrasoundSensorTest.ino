int dist;
int dur;
const byte trig = 10; 
const byte echo = 9;


// Function used to get the distance between an object
// and the sensor
void get_dist(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  dur = pulseIn(echo, HIGH);
  dist = dur*0.034/2;
}



void setup(){
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}


void loop(){
  get_dist();
  Serial.println("Object is " + String(dist) + " cm away");
  delay(100);
}
