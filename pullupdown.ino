/*

  CIRCUITO:
  Pin 2: Botón de Datos (LED) conectado a GND
  Pin 3: Botón de Modo   -> conectado a GND
  Pin 4: Resistencia 220ohm -> LED -> GND

*/

// Pines
const int dataButtonPin = 2;
const int modeButtonPin = 3;
const int ledPin = 4;

// Variables de Modo
// estado = HIGH significa Modo Pull-Up (Press=0)
// estado = LOW significa Modo Pull-Down (Press=1)
int estado = HIGH;

// Variables de Antirrebote (Debounce) para el BOTÓN DE MODO (Pin 3)
int modeButtonState = HIGH;         // El estado estable actual del botón de modo
int lastModeState = HIGH;           // La lectura en bruto anterior del botón de modo
unsigned long lastDebounceTime = 0; // Última vez que cambió
unsigned long debounceDelay = 50;   // 50ms de espera
