#include <LiquidCrystal_I2C.h>

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif

uint8_t bell[8]  = {0x4,0xe,0xe,0xe,0x1f,0x0,0x4};
uint8_t note[8]  = {0x2,0x3,0x2,0xe,0x1e,0xc,0x0};
uint8_t clock[8] = {0x0,0xe,0x15,0x17,0x11,0xe,0x0};
uint8_t heart[8] = {0x0,0xa,0x1f,0x1f,0xe,0x4,0x0};
uint8_t duck[8]  = {0x0,0xc,0x1d,0xf,0xf,0x6,0x0};
uint8_t check[8] = {0x0,0x1,0x3,0x16,0x1c,0x8,0x0};
uint8_t cross[8] = {0x0,0x1b,0xe,0x4,0xe,0x1b,0x0};
uint8_t retarrow[8] = {0x1,0x1,0x5,0x9,0x1f,0x8,0x4};

uint8_t logo_2x2[4][8] = { 
  {0x0, 0x0, 0x0, 0x7, 0xC, 0x18, 0x10, 0x10}, 
  {0x0, 0x0, 0x0, 0x4, 0x4, 0x1F, 0x4, 0x4}, 
  {0x10, 0x10, 0x18, 0xC, 0x7, 0x0, 0x0, 0x0}, 
  {0x1F, 0x5, 0x5, 0xC, 0x18, 0x0, 0x0, 0x0}
};

byte arrow[] = {0x00,0x08,0x04,0x02,0x02,0x04,0x08,0x00};

LiquidCrystal_I2C lcd2(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

const int buttonUp = 10;
const int buttonDown = 11;
const int ledRed = 12;
const int ledYellow = 13;

enum State {
  STATE_INITIAL,
  STATE_SECOND,
  STATE_THIRD
};

State currentState = STATE_INITIAL;

void setup() {
  pinMode(buttonUp, INPUT);
  pinMode(buttonDown, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledYellow, HIGH);

  lcd2.init();
  lcd2.backlight();
  lcd2.blink();
  // Create the custom characters
  lcd2.createChar(0, logo_2x2[0]);
  lcd2.createChar(1, logo_2x2[1]);
  lcd2.createChar(2, logo_2x2[2]);
  lcd2.createChar(3, logo_2x2[3]);
  lcd2.createChar(4, arrow);
  lcd2.home();
}

void displayInitialScreen() {
  
  lcd2.setCursor(9, 0); // Top left
  lcd2.printByte(0);
  lcd2.setCursor(10, 0); // Top right
  lcd2.printByte(1);
  lcd2.setCursor(9, 1); // Bottom left
  lcd2.printByte(2);
  lcd2.setCursor(10, 1); // Bottom right
  lcd2.printByte(3);
  lcd2.setCursor(4, 2);
  lcd2.print("Gamma Tracker");
  lcd2.setCursor(19,3);
  lcd2.printByte(4);
  lcd2.setCursor(12,3);
  lcd2.print("Iniciar");
}

void displaySecondScreen() {
  
  lcd2.setCursor(0, 0);
  lcd2.print("Second Screen");
}

void displayThirdScreen() {
  
  lcd2.setCursor(0, 0);
  lcd2.print("Third Screen");
}

void loop() {
  byte buttonUpState = digitalRead(buttonUp);
  byte buttonDownState = digitalRead(buttonDown);

  if (buttonUpState == LOW) {
    currentState = static_cast<State>((currentState + 1) % 3);
    delay(200); // Debounce delay
    lcd2.clear();
  }

  if (buttonDownState == LOW) {
    currentState = static_cast<State>((currentState + 2) % 3); // Go back
    delay(200); // Debounce delay
    lcd2.clear();
  }

  switch (currentState) {
    case STATE_INITIAL:
      displayInitialScreen();
      break;
    case STATE_SECOND:
      displaySecondScreen();
      break;
    case STATE_THIRD:
      displayThirdScreen();
      break;
  }

  // LED Control based on button state
  digitalWrite(ledRed, buttonUpState == LOW ? HIGH : LOW);
  digitalWrite(ledYellow, buttonDownState == LOW ? HIGH : LOW);
}
