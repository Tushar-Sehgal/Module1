const int motionPin = 2;  // Pin for the motion sensor
const int ledPin = 13;    // Pin for the built-in LED

volatile bool motionDetected = false; // Volatile variable to track motion

void setup() {
  pinMode(motionPin, INPUT); // Set motion pin as input
  pinMode(ledPin, OUTPUT);   // Set LED pin as output
  Serial.begin(9600);        // Begin serial communication

  // Set up the interrupt on the motionPin, trigger on any change
  attachInterrupt(digitalPinToInterrupt(motionPin), motionISR, CHANGE);
}

void loop() {
  // The loop can contain any non-critical code
  delay(1000); // Example delay
}

// Interrupt Service Routine (ISR) for motion detection
void motionISR() {
  // Read the motion sensor state
  int motionState = digitalRead(motionPin);
  
  // Control the LED based on the motion sensor state
  if (motionState == HIGH) {
    digitalWrite(ledPin, HIGH); // Turn on LED
    if (!motionDetected) {
      Serial.println("Motion detected!");
      motionDetected = true; // Set the flag to avoid repetitive messages
    }
  } else {
    digitalWrite(ledPin, LOW);  // Turn off LED
    if (motionDetected) {
      Serial.println("Motion stopped.");
      motionDetected = false; // Reset the flag
    }
  }
}
