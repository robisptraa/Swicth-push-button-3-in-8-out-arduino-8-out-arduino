//CODE BY robisptraa
const int buttonPin = A0; 
const int button2Pin = A1;
const int button3Pin = A2; 

const int ledPins[] = {2, 3, 4, 5, 6, 7}; 
const int led2Pin = 12;   
const int led3Pin = 13;  

int currentLed = 0;
bool lastButtonState = LOW;
bool lastButton2State = LOW;
bool lastButton3State = LOW;
bool buttonPressed = false;
bool led2State = LOW;     
bool led3State = LOW;      

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], HIGH);
  }
  
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
  

  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  

  digitalWrite(led2Pin, LOW);
  digitalWrite(led3Pin, LOW);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && lastButtonState == HIGH && !buttonPressed) {
    buttonPressed = true;
    digitalWrite(ledPins[currentLed], HIGH); 
    currentLed = (currentLed + 1) % 6;
    digitalWrite(ledPins[currentLed], LOW);  
  }
  if (buttonState == HIGH) {
    buttonPressed = false;
  }
  lastButtonState = buttonState;


  bool button2State = digitalRead(button2Pin);
  if (button2State == HIGH && lastButton2State == LOW) {
    led2State = !led2State; 
    digitalWrite(led2Pin, led2State);
  }
  lastButton2State = button2State;

  bool button3State = digitalRead(button3Pin);
  if (button3State == HIGH && lastButton3State == LOW) {
    led3State = !led3State; 
    digitalWrite(led3Pin, led3State);
  }
  lastButton3State = button3State;
}