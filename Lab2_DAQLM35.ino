// --- Definición de Pines ---
const int SENSOR_PIN = A0;
const int LED_VERDE_PIN = 7;
const int LED_AMARILLO_PIN = 8;
const int LED_ROJO_PIN = 9;

// --- Configuración para el promedio ---
const int NUM_MUESTRAS = 10;

void setup() {
  Serial.begin(9600);
  
  // Configurar los tres LEDs como SALIDA
  pinMode(LED_VERDE_PIN, OUTPUT);
  pinMode(LED_AMARILLO_PIN, OUTPUT);
  pinMode(LED_ROJO_PIN, OUTPUT);
  
  // Asegurarse que todos empiecen apagados
  digitalWrite(LED_VERDE_PIN, LOW);
  digitalWrite(LED_AMARILLO_PIN, LOW);
  digitalWrite(LED_ROJO_PIN, LOW);
}
void loop() {
  
  // --- Lectura y Cálculo de Temperatura ---
  int totalLecturas = 0;
  for (int i = 0; i < NUM_MUESTRAS; i++) {
    totalLecturas += analogRead(SENSOR_PIN);
    delay(2);
  }
}