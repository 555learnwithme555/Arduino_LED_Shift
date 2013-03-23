 
int leds[] = {5,6,7,8};

int button = 12;
int buttonCurrentState; 
int buttonPrevState;
int led = 13;

int counter = 0;

int i;

void setup() {                
  
  for (i = 0; i < 4; i = i + 1) {
    pinMode(leds[i], OUTPUT);
  }
  
  pinMode(led, OUTPUT);

  digitalWrite(led, LOW);

  pinMode(button, INPUT_PULLUP);
}

void loop() {
  
  buttonCurrentState = digitalRead(button);
  
  if (buttonCurrentState == LOW && buttonPrevState == HIGH) {
    
    counter++;
    
    if (counter == 4) {
       counter = 0; 
    }

    for (i = 0; i < 4; i = i + 1) {
      
      if (i == counter) {
        digitalWrite(leds[i], HIGH);
      }else {
        digitalWrite(leds[i], LOW);
      }
    }
    
    digitalWrite(led, HIGH);
    delay(250);
  }else {
    digitalWrite(led, LOW);
  }

  buttonPrevState = buttonCurrentState;

}
