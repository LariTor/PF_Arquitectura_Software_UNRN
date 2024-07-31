# Design Patterns Utilizados en el Proyecto

En este proyecto de Sistema de Visualización y Alerta de Datos Mediante USB, se han implementado varios patrones de diseño para asegurar una arquitectura robusta, modular y extensible. Los principales patrones utilizados son el Singleton y el State.

## [Singleton Pattern](https://refactoring.guru/design-patterns/singleton)

El patrón Singleton se asegura de que una clase tenga una única instancia y proporciona un punto de acceso global a ella. En este proyecto, el patrón Singleton se utiliza para gestionar el contexto global de la aplicación, garantizando que solo exista una instancia de la clase Context durante la ejecución del programa.

### Implementación del código

```cpp
class Context
{
private:
    static Context *instance;
    State *currentState;
    // Asegura que el constructor sea privado para evitar múltiples instancias
    Context() : currentState(nullptr) {}

public:
    static Context *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Context();
        }
        return instance;
    }

    void setState(State *state)
    {
        if (currentState != nullptr)
        {
            delete currentState;
        }
        currentState = state;
    }

    void handleUp() { currentState->handleUp(this); }
    void handleDown() { currentState->handleDown(this); }
    void handleSelect() { currentState->handleSelect(this); }
    void handleBack() { currentState->handleBack(this); }
    void displayMenu() { currentState->displayMenu(this); }
};

```
### Beneficios de usar singleton

- Control de Acceso a Recursos: Garantiza un único punto de acceso y control a recursos compartidos, evitando conflictos y duplicaciones.
- Consistencia Global: Asegura que todas las partes del programa interactúan con la misma instancia, manteniendo la consistencia del estado global.

## [State Pattern](https://refactoring.guru/design-patterns/state)

El patrón State permite que un objeto altere su comportamiento cuando su estado interno cambia. Este patrón es ideal para situaciones donde un objeto debe cambiar su comportamiento en función de su estado. En este proyecto, el patrón State se utiliza para manejar los diferentes estados del sistema, como ConfigState, WaitingSampleState, SamplingState, y ErrorState.

### Implementación del código

Cada estado hereda de una clase base State y sobreescribe los métodos correspondientes:

```cpp

class State
{
public:
    virtual void handleUp(Context *context) = 0;
    virtual void handleDown(Context *context) = 0;
    virtual void handleSelect(Context *context) = 0;
    virtual void handleBack(Context *context) = 0;
    virtual void displayMenu(Context *context) = 0;
    virtual ~State() {}
};

```
Ejemplo de estado config state:

``` cpp
class ConfigState : public State
{
public:
    ConfigState(LiquidCrystal_I2C &lcd);

    void handleUp(Context *context) override;

    void handleDown(Context *context) override;

    void handleSelect(Context *context) override;

    void handleBack(Context *context) override;

    void displayMenu(Context *context) override;

private:
    int currentIndex;
    LiquidCrystal_I2C &lcd;

    void initializeLcd();

    void printLogo();

    static const char *menuItems[];
    static const int menuLength;
};
```

### Beneficios de usar state

- Simplificación de la Lógica de Transición: Facilita el manejo de las transiciones entre diferentes estados, evitando múltiples condiciones complejas.
- Responsabilidad Única: Cada estado es responsable de su propio comportamiento, siguiendo el principio de responsabilidad única.
- Extensibilidad: Permite agregar nuevos estados sin modificar los existentes, facilitando la ampliación de funcionalidades.

## Conclusiones
El uso de los patrones Singleton y State en este proyecto ha permitido construir un sistema organizado, modular y fácil de mantener. El Singleton asegura que haya una única instancia de la clase Context, mientras que el patrón State facilita la gestión y transición entre diferentes estados del sistema, mejorando la claridad y estructura del código.
