#include <LiquidCrystal_I2C.h>
#include "pins.h"
#include "custom_char.h"

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args) write(args);
#else
#define printByte(args) print(args, BYTE);
#endif

// Define el estado de la pantalla
enum ScreenState
{
  MENU,
  CONFIGURATION,
  RANGE,
  DATE_TIME
};

ScreenState currentScreen = MENU;

void setup()
{
  initPins();

  digitalWrite(led_red, HIGH);
  digitalWrite(led_yellow, HIGH);

  lcd.init();
  lcd.backlight();
  lcd.blink();
  // Create the custom characters
  lcd.createChar(0, logo_2x2[0]);
  lcd.createChar(1, logo_2x2[1]);
  lcd.createChar(2, logo_2x2[2]);
  lcd.createChar(3, logo_2x2[3]);
  lcd.createChar(4, arrow);
  lcd.home();
}

void loop()
{
  byte button_upState = digitalRead(button_up);
  byte button_downState = digitalRead(button_down);
  byte button_selectState = digitalRead(button_select);
  byte button_backState = digitalRead(button_back);

  // Lógica para cambiar el estado de la pantalla
  if (button_upState == LOW)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Hola bUTTON uP");
  }
  if (button_downState == LOW)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Hola bUTTON DOWN");
  }
  if (button_selectState == LOW)
  {
    // Implementa la lógica para seleccionar una opción
    if (currentScreen == MENU)
    {
      // Cambia de pantalla según la selección en el menú
      // Aquí debes definir cómo seleccionas las opciones
    }
  }
  if (button_backState == LOW)
  {
    // Regresa al menú principal
    currentScreen = MENU;
  }

  // Lógica para mostrar la pantalla actual
  switch (currentScreen)
  {
  case MENU:
    displayMenu();
    break;
  case CONFIGURATION:
    displayConfiguration();
    break;
  case RANGE:
    displayRange();
    break;
  case DATE_TIME:
    displayDateTime();
    break;
  }
}

void displayMenu()
{
  lcd.setCursor(0, 0);
  lcd.print("Menu de inicio");
  lcd.print("Opcion 1...");
}

void displayConfiguration()
{
  lcd.setCursor(0, 0);
  lcd.print("Configuracion");
  // Muestra la pantalla de configuración
}

void displayRange()
{
  lcd.setCursor(0, 0);
  lcd.print("Limite Inferior: 0");
  lcd.setCursor(0, 1);
  lcd.print("Limite Superior: 100");
  // Muestra la pantalla de rango
}

void displayDateTime()
{
  lcd.setCursor(0, 0);
  lcd.print("Fecha y Hora");
  // Muestra la pantalla de fecha y hora
}
