// received command from BT
char comanda = '0';

// motors
int In1 = 7;
int In2 = 6;
int In3 = 5;
int In4 = 4;

//buzzer
int buzzer = 12;
//leds
int led = 11;

//low voltage for led
int voltLow = 10;
//high voltage for led
int voltHigh = 80;

int current = voltLow;


int ENA = 8;
int ENB = 9;


// motors speed
int SPEED = 220;

void setup() {

  // pin setup
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(buzzer, OUTPUT);
  
  pinMode(led, OUTPUT);

  // BT
  Serial.begin(9600);
}

void loop() {
  //led
  analogWrite(led,current);

  if (Serial.available() > 0) {
    comanda = Serial.read();
    Serial.println(comanda);
  }

    if (comanda == 'F') {
      //forward
      digitalWrite(In1, HIGH);
      digitalWrite(In2, LOW);
      digitalWrite(In3, HIGH);
      digitalWrite(In4, LOW);
    } else if (comanda == 'B') {
      // backward
      digitalWrite(In1, LOW);
      digitalWrite(In2, HIGH);
      digitalWrite(In3, LOW);
      digitalWrite(In4, HIGH);
    } else if (comanda == 'L') {
      // left
      digitalWrite(In1, LOW);
      digitalWrite(In2, LOW);
      digitalWrite(In3, HIGH);
      digitalWrite(In4, LOW);
    } else if (comanda == 'R') {
      // right
      digitalWrite(In1, HIGH);
      digitalWrite(In2, LOW);
      digitalWrite(In3, LOW);
      digitalWrite(In4, LOW);
    } else if (comanda == 'H') {
      // play the buzzer
      tone(buzzer, 1000);
    } else if (comanda == 'S'){
      // stop all
      digitalWrite(In1, LOW);
      digitalWrite(In2, LOW);
      digitalWrite(In3, LOW);
      digitalWrite(In4, LOW);
      noTone(buzzer);
      current = voltLow;

    } else if (comanda == '1'){
      //make leds go flash
      current = voltHigh;
    }
}
