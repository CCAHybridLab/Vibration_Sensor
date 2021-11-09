const int LED = 9; //Buzzer connected to pin 8 of Arduino uno / mega
int vibSensor;           //Variable to store analog value (0-1023)
int lightVal;


void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop(){
  vibSensor = analogRead(A0);
  lightVal = map(vibSensor, 400, 1024, 0, 255); //map the sensor value to LED brightness
  
  if (vibSensor>400){
    analogWrite(LED, lightVal);
    Serial.print("Sensor Value: ");
    Serial.println(vibSensor);
  }
  else{
    digitalWrite(LED, LOW); 
    Serial.print("Sensor Value: ");
    Serial.println(vibSensor);
  }
  delay(50);
}
