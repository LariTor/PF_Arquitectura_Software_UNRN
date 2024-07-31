/**
 * @file sampling_state.ino
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "sampling_state.h"
#include "errorSample_state.h"
#include "serialNotConnectedError_decorator.h"
#include "noDataError_decorator.h"
#include "waitingSample_state.h"
#include "menu_state.h"
#include "context.h"
#include "pins.h"
#include "custom_char.h"

SamplingState::SamplingState(LiquidCrystal_I2C &lcd) : lcd(lcd) { Serial.begin(9600); }

void SamplingState::handleUp(Context *context)
{
    // No action needed for Up in Sampling state
}

void SamplingState::handleDown(Context *context)
{
    // No action needed for Down in Sampling state
}

void SamplingState::handleSelect(Context *context)
{
    if (Serial.available() > 0)
    {
        countNumbersInRange(context);
    }
}

void SamplingState::handleBack(Context *context)
{
    context->setState(new WaitingSampleState(lcd)); // Transition to MenuState on back
}

void SamplingState::displayMenu(Context *context)
{
    initializeLcd();
    printLogo();
    lcd.setCursor(0, 0);
    lcd.printByte(0);
    lcd.print("Muestreo");
    lcd.setCursor(0, 1);
    lcd.print("I:");
    const char *Iso = context->getIsotope();
    lcd.print(Iso);
    lcd.setCursor(0, 2);
    lcd.print("Rs:");
    int Rsup = context->getUpperLimit();
    lcd.print(Rsup);
    lcd.setCursor(0, 3);
    lcd.print("Ri:");
    int Rlow = context->getLowerLimit();
    lcd.print(Rlow);
    lcd.setCursor(6, 1);
    lcd.print("|");
    lcd.setCursor(6, 2);
    lcd.print("|");
    lcd.setCursor(6, 3);
    lcd.print("|");
    lcd.setCursor(7, 2);
    lcd.print("Cuentas:0");
    lcd.setCursor(7, 3);
    lcd.print("Estado:");
    lcd.print("SAMPLE");
}

void SamplingState::printLogo()
{
    lcd.setCursor(18, 0);
    lcd.printByte(1);
    lcd.setCursor(19, 0);
    lcd.printByte(2);
    lcd.setCursor(18, 1);
    lcd.printByte(3);
    lcd.setCursor(19, 1);
    lcd.printByte(4);
}

void SamplingState::initializeLcd()
{
    lcd.clear();
    lcd.noBlink();
    lcd.setCursor(0, 0);
    lcd.createChar(0, sample_icon);
    lcd.createChar(1, logo_2x2[0]);
    lcd.createChar(2, logo_2x2[1]);
    lcd.createChar(3, logo_2x2[2]);
    lcd.createChar(4, logo_2x2[3]);
    lcd.home();
}

void SamplingState::buzzerFunc(int value, int Rlow, int Rsup)
{
    int frequency;
    if (value < Rlow)
    {
        frequency = 100; // Low frequency for values below the range
    }
    else if (value > Rsup)
    {
        frequency = 1000; // High frequency for values above the range
    }
    else
    {
        frequency = 100 + ((value - Rlow) * 900) / (Rsup - Rlow); // Scale frequency between 100 and 1000
    }
    tone(buzzer, frequency);
}

void SamplingState::updateLCD(int count)
{
    lcd.setCursor(7, 2);
    lcd.print("Cuentas: ");
    lcd.print(count);
}

void SamplingState::countNumbersInRange(Context *context)
{
    int Rlow = context->getLowerLimit();
    int Rsup = context->getUpperLimit();
    int count = 0;

    unsigned long startMillis = millis(); // Guardar el tiempo de inicio
    unsigned long currentMillis;

    bool serialConnected = Serial; // Verificar si el Serial está conectado

    bool validData = false;

    while (true)
    {
        currentMillis = millis();

        // Verificar si el Serial está conectado
        if (!serialConnected)
        {
            context->setState(new ErrorSampleState(context->getLcd(), new SerialNotConnectedErrorDecorator(nullptr)));
            break;
        }

        // Verificar si ha pasado mucho tiempo sin recibir datos
        if (currentMillis - startMillis > 10000)
        { // 10 segundos sin recibir datos
            context->setState(new ErrorSampleState(context->getLcd(), new NoDataErrorDecorator(nullptr)));
            break;
        }

        // Verificar si hay datos disponibles en el puerto serie
        if (Serial.available() > 0)
        {
            int value = Serial.parseInt(); // Leer el valor del puerto serie

            // Verificar si los primeros números recibidos son "1111"
            if (!validData)
            {
                if (value == 1111)
                {
                    validData = true;
                    Serial.println("Datos iniciales válidos.");
                }
                else
                {
                    context->setState(new ErrorSampleState(context->getLcd(), new SerialNotConnectedErrorDecorator(nullptr)));
                    break;
                }
            }
            else
            {
                // Continuar procesando los datos válidos
                if (value >= Rlow && value <= Rsup)
                {
                    count++;
                    buzzerFunc(value, Rlow, Rsup);
                    delay(100); // Delay for buzzer tone duration
                }

                // Actualizar el LCD con el conteo de cuentas
                lcd.setCursor(7, 2);
                lcd.print("Cuentas:");
                lcd.print(count);
                noTone(buzzer);

                // Reiniciar el temporizador ya que se recibieron datos
                startMillis = currentMillis;
            }
        }

        // Verificar si el botón "Back" fue presionado
        if (digitalRead(button_back) == LOW)
        {
            Serial.println("Botón BACK presionado. Interrumpiendo medición.");
            handleBack(context); // Cambiar el estado a WaitingSampleState
            return;
        }
    }
}