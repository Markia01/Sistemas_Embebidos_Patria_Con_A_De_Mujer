// --- Definición de Pines ---
const int SENSOR_PIN = A0;
const int LED_VERDE_PIN = 7;
const int LED_AMARILLO_PIN = 8;
const int LED_ROJO_PIN = 9;

// --- Configuración para el promedio ---
const int NUM_MUESTRAS = 10;

void setup()
{
  Serial.begin(9600);

  // Configurar los tres LEDs como SALIDA
  pinMode(LED_VERDE_PIN, OUTPUT);
  pinMode(LED_AMARILLO_PIN, OUTPUT);
  pinMode(LED_ROJO_PIN, OUTPUT);

  // Asegurar que todos comiencen apagados
  digitalWrite(LED_VERDE_PIN, LOW);
  digitalWrite(LED_AMARILLO_PIN, LOW);
  digitalWrite(LED_ROJO_PIN, LOW);
}
void loop()
{

  // --- Lectura y Cálculo de Temperatura ---
  int totalLecturas = 0;
  for (int i = 0; i < NUM_MUESTRAS; i++)
  {
    totalLecturas += analogRead(SENSOR_PIN);
    delay(2);
  }

  float promedio = (float)totalLecturas / (float)NUM_MUESTRAS;
  float voltaje = (promedio / 1023.0) * 5.0;
  float tempC = voltaje * 100.0;

  // --- se imprimen todos los valores ---
  Serial.print("Valor Raw (promedio): ");
  Serial.print(promedio); // Este es el valor analógico (0-1023)
  Serial.print(" | Voltaje: ");
  Serial.print(voltaje, 3); // Muestra el voltaje con 3 decimales
  Serial.print(" V | Temp: ");
  Serial.print(tempC);
  Serial.println(" C");


// --- Lógica de LEDs por Rango ---
  // Esta estructura asegura que solo un bloque de código se ejecute
  
  // Rango Verde (15.0 a 25.0 C)
  if (tempC >= 15.0 && tempC <= 25.0) {
    digitalWrite(LED_VERDE_PIN, HIGH);
    digitalWrite(LED_AMARILLO_PIN, LOW);
    digitalWrite(LED_ROJO_PIN, LOW);
    Serial.println("--- LED VERDE ---");
  } 
  // Rango Amarillo (26.0 a 36.0 C)
  else if (tempC >= 26.0 && tempC <= 36.0) {
    digitalWrite(LED_VERDE_PIN, LOW);
    digitalWrite(LED_AMARILLO_PIN, HIGH);
    digitalWrite(LED_ROJO_PIN, LOW);
    Serial.println("--- LED AMARILLO ---");
  }
 // Rango Rojo (Más de 36.0 C)
  else if (tempC > 36.0) {
    digitalWrite(LED_VERDE_PIN, LOW);
    digitalWrite(LED_AMARILLO_PIN, LOW);
    digitalWrite(LED_ROJO_PIN, HIGH);
    Serial.println("--- LED ROJO ---");
  }
  // Si no está en ningún rango (ej. menos de 15.0 C o entre 25.1 y 25.9)
  else {
    digitalWrite(LED_VERDE_PIN, LOW);
    digitalWrite(LED_AMARILLO_PIN, LOW);
    digitalWrite(LED_ROJO_PIN, LOW);
  }

 delay(1000);
}