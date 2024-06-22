// Motor control pins
int enA = 5; // PWM pin for motor 1 speed control (ENA)
int in1 = 2; // Motor 1 direction control (IN1)
int in2 = 3; // Motor 1 direction control (IN2)
int enB = 6; // PWM pin for motor 2 speed control (ENB)
int in3 = 4; // Motor 2 direction control (IN3)
int in4 = 7; // Motor 2 direction control (IN4)
char command = 0;
void setup() {
  // Set motor control pins as OUTPUT
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  // Initialize serial communication
  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Serial.print(command);

    // Motor control based on received command
    if (command == 'B') {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enA, 255); // Full speed (255) 
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enB, 255); // Full speed (255) 
    } else if (command == 'F') {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(enA, 255); // Full speed (255)
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enB, 255); // Full speed (255) 
    } else if (command == 'L') {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(enA, 255); // Adjust speed as needed
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enB, 255); // Adjust speed as needed
    } else if (command == 'R') {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enA, 255); // Adjust speed as needed
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enB, 255); // Adjust speed as needed
    } else if (command == 'H') {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enA, 255); // Full speed (255) forward
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enB, 40); // Adjust speed as needed for diagonal movement
    } else if (command == 'J') {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enA, 40); // Adjust speed as needed for diagonal movement
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enB, 255); // Full speed (255) forward
    } else if (command == 'I') {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(enA, 40); // Adjust speed as needed for diagonal movement
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enB, 255); // Full speed (255) backward
    } else if (command == 'G') {
      // Move backward-right (one motor backward but slower, one motor backward)
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(enA, 255); // Full speed (255) backward
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enB, 40); // Adjust speed as needed for diagonal movement
    } else if (command == 'S') {
      // Stop
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      analogWrite(enA, 0); // Stop motor 1
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      analogWrite(enB, 0); // Stop motor 2
    }
  }
}
