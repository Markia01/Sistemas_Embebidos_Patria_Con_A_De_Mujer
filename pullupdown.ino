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

void setup() {
  Serial.begin(9600);
  
  // Ambos botones usan la resistencia PULLUP interna
  pinMode(dataButtonPin, INPUT_PULLUP); // Botón de Datos
  pinMode(modeButtonPin, INPUT_PULLUP); // Botón de Modo
  
  pinMode(ledPin, OUTPUT); // Pin del LED
  
  // Serial.println("Modo inicial: Pull-Up (Presionar = 0)"); // COMENTADO para Plotter limpio
}

void loop() {
  
  //  Lógica del Botón de Modo (Pin 3) con Debounce
  
  int pinEstado = digitalRead(modeButtonPin); // Leer el botón de modo
  
  // Si la lectura es diferente a la anterior, reiniciar el contador
  if (pinEstado != lastModeState) {
    lastDebounceTime = millis();
  }
  
}
  // Si ha pasado suficiente tiempo desde el último cambio
  if ((millis() - lastDebounceTime) > debounceDelay) {
    
    // Si el estado estable ha cambiado (es una nueva presión)
    if (pinEstado != modeButtonState) {
      modeButtonState = pinEstado; // Guardar el nuevo estado estable

      // Si el nuevo estado estable es PRESIONADO (LOW)
      if (modeButtonState == LOW) {
        estado = !estado; // Invertir el modo
        // Imprimir el nuevo modo en el Serial Monitor
      }
    }
  }
  lastModeState = pinEstado; // Guardar la lectura en bruto para el próximo ciclo

