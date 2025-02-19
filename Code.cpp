int water; //random variable
void setup() {
pinMode(3,OUTPUT); //output pin for relay board, this will sent signal to the relay
pinMode(6,INPUT); //input pin coming from soil sensor
}
void loop() {
water = digitalRead(6); // reading the coming signal from the soil sensor
if(water == HIGH) // if water level is full then cut the relay
{
digitalWrite(3,LOW); // low is to cut the relay
}else{
digitalWrite(3,HIGH); //high to continue proving signal and water supply
}
delay(400);
}



int soilMoisture;          // Variable to store the analog reading from the sensor
const int moisturePin = A0; // Analog pin connected to the soil moisture sensor
const int relayPin = 3;     // Output pin for relay board
const int threshold = 60;   // Threshold value for dry soil (adjust as needed)

void setup() {
  pinMode(relayPin, OUTPUT);    // Output pin for controlling relay
  pinMode(moisturePin, INPUT);  // Input pin for reading moisture sensor
  Serial.begin(9600);           // Start serial communication at 9600 baud rate
}

void loop() {
  soilMoisture = analogRead(moisturePin); // Read analog value from soil moisture sensor
  
  // Display soil moisture reading on Serial Monitor
  Serial.print("Soil Moisture Level: ");
  Serial.println(soilMoisture);
  
  // Check moisture level and control relay
  if (soilMoisture < threshold) {    // If soil moisture is below threshold (soil is wet)
    digitalWrite(relayPin, LOW);     // Turn off relay (stop water supply)
    Serial.println("Water Supply: OFF"); // Show status on Serial Monitor
  } else {                           // If soil moisture is above threshold (soil is dry)
    digitalWrite(relayPin, HIGH);    // Turn on relay (start water supply)
    Serial.println("Water Supply: ON");  // Show status on Serial Monitor
  }

  delay(400); // Delay for stability (adjust as needed)
}
