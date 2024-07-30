const int motionPin = 2;  // Pin for the motion sensor
const int ledPin = 13;    // Pin for the built-in LED

void setup() {
  pinMode(motionPin, INPUT); // Set motion pin as input
  pinMode(ledPin, OUTPUT);   // Set LED pin as output
  Serial.begin(9600);        // Begin serial communication
}

void loop() {
  int motionStatus = digitalRead(motionPin); // Read motion sensor
  if (motionStatus == HIGH) {
    digitalWrite(ledPin, HIGH); // Turn on LED
    Serial.println("Motion detected!");
  } else {
    digitalWrite(ledPin, LOW);  // Turn off LED
    Serial.println("No motion.");
  }
  delay(1000); // Delay for stability
}
