// Pin connections
const int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8};
const int commonPin = 9;

// Two-dimensional array to store segment patterns for digits 0 to 9
const byte digitPatterns[10][7] = {
  {B11111100, B01100000, B11011010, B11110010, B01100110, B10110110, B10111110}, // 0
  {B01100000, B11011010, B11110010, B01100110, B10110110, B10111110, B11100000}, // 1
  //... Patterns for digits 2 to 9
};

void setup() {
  // Set segment pins as outputs
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  
  // Set common pin as output
  pinMode(commonPin, OUTPUT);
}

void loop() {
  // Display digits 0 to 9
  for (int i = 0; i < 10; i++) {
    displayDigit(i);
    delay(1000); // Delay for one second
  }
}

void displayDigit(int digit) {
  // Turn off all segments
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], HIGH);
  }
  
  // Set the pattern for the specified digit
  byte pattern[7];
  memcpy(pattern, digitPatterns[digit], 7);
  
  // Apply the pattern to the segment pins
  for (int i = 0; i < 7; i++) {
    bool segmentState = bitRead(pattern[i], i);
    digitalWrite(segmentPins[i], !segmentState);
  }
  
  // Enable the common pin to display the digit
  digitalWrite(commonPin, LOW);
  delay(5); // Adjust this delay as needed for visibility
  digitalWrite(commonPin, HIGH);
}