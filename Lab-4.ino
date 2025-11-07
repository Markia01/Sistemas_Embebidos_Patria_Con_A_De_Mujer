#include "DHT.h"

// --- Definiciones de Pines ---
#define DHTPIN 2      // Pin de datos del DHT11
#define DHTTYPE DHT11 // Tipo de sensor
#define BOTON_PIN 3   // Pin del botón de inicio
#define LED_VERDE_PIN 7
#define LED_AMARILLO_PIN 8
#define LED_ROJO_PIN 9

// Inicializa el objeto sensor
DHT dht(DHTPIN, DHTTYPE);

// --- Variables Globales ---
// Guardamos el estado anterior del botón para detectar CADA "click"
int ultimoEstadoBoton = HIGH; // HIGH (suelto) por el INPUT_PULLUP

void setup()
{
  Serial.begin(9600);
  Serial.println(F("Sistema de Monitoreo de Clima - ITIID"));

  // Configura el botón. INPUT_PULLUP usa la resistencia interna de Arduino.
  // El botón debe estar conectado entre el pin 3 y GND (Tierra).
  // Presionado = LOW (0), Suelto = HIGH (1).
  pinMode(BOTON_PIN, INPUT_PULLUP);

  // Configura los LEDs como salida
  pinMode(LED_VERDE_PIN, OUTPUT);
  pinMode(LED_AMARILLO_PIN, OUTPUT);
  pinMode(LED_ROJO_PIN, OUTPUT);

  // Apaga todos los LEDs al iniciar
  digitalWrite(LED_VERDE_PIN, LOW);
  digitalWrite(LED_AMARILLO_PIN, LOW);
  digitalWrite(LED_ROJO_PIN, LOW);

  // Inicia el sensor
  dht.begin();
  Serial.println(F("Sensor DHT11 inicializado."));
  Serial.println(F("Presiona el boton para realizar una medicion..."));
}

void loop()
{
  // --- REQUISITO 1: Esperar al botón (Lógica de "Una Sola Medición") ---

  // 1. Leemos el estado actual del botón
  int estadoActual = digitalRead(BOTON_PIN);

  // 2. Comparamos el estado actual con el anterior
  // ¿El botón ESTÁ presionado (LOW) y ANTES estaba suelto (HIGH)?
  if (estadoActual == LOW && ultimoEstadoBoton == HIGH)
  {

    // ¡Sí! Es un nuevo "click". Realizamos UNA lectura.
    Serial.println(F("--------------------------------"));
    Serial.println(F("Boton presionado. Realizando lectura..."));

    realizarLectura(); // Llamamos a la función que mide y enciende LEDs

    // Pequeña pausa para el "debounce" (antirrebote)
    // Esto evita que un solo "click" se registre varias veces.
    delay(50);
  }

  // 3. Actualizamos el estado "anterior" para la próxima vuelta del loop

  ultimoEstadoBoton = estadoActual;

  // No se necesita delay aquí, el loop debe ser rápido
  // para detectar el "click" al instante.
}

/**
 * @brief Realiza una lectura del sensor, la imprime y controla los LEDs.
 **/
void realizarLectura()
{

  // Leemos los datos del sensor
  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();

  // Verificamos si la lectura falló
  if (isnan(humedad) || isnan(temperatura))
  {
    Serial.println(F("Error al leer del sensor DHT11!"));
    Serial.println(F("Asegura que la resistencia de PULL-UP (Req. 3) esté conectada."));
    return; // Salimos de la función si hay error
  }

  // --- REQUISITO 2: Fórmula de Sensación Térmica ---
  float sensacionTermica = dht.computeHeatIndex(temperatura, humedad, false);

  // Imprimimos los valores
  Serial.print(F("Humedad: "));
  Serial.print(humedad);
  Serial.print(F("%, Temperatura: "));
  Serial.print(temperatura);
  Serial.print(F("°C, "));
  Serial.print(F("Sensacion Termica: "));
  Serial.print(sensacionTermica);
  Serial.println(F("°C"));

  // --- REQUISITO 4: Estructura de Control de LEDs ---

  // 1. Primero, apagamos todos para empezar de cero
  digitalWrite(LED_VERDE_PIN, LOW);
  digitalWrite(LED_AMARILLO_PIN, LOW);
  digitalWrite(LED_ROJO_PIN, LOW);
// 2. Evaluamos la temperatura y encendemos el LED correcto
  if (temperatura >= 15.0 && temperatura <= 25.0) {
    // "Si Temperatura esta entre 15°c y 25°c encender un led verde"
    digitalWrite(LED_VERDE_PIN, HIGH);
    Serial.println(F("Estado: CONFORTABLE (Verde)"));
  } 
  else if (temperatura >= 26.0 && temperatura <= 35.0) {
    // "Si Temperatura esta entre 26 y 35 °c encender un led amarillo"
    digitalWrite(LED_AMARILLO_PIN, HIGH);
    Serial.println(F("Estado: CALIDO (Amarillo)"));
  } 
  else if (temperatura > 35.0) {
    // "Si Temperatura es mayor a 35°c led Rojo"
    digitalWrite(LED_ROJO_PIN, HIGH);
    Serial.println(F("Estado: MUY CALIENTE (Rojo)"));
  }
  else {
    // Si es menor a 15°C (o cualquier otro caso no cubierto)
    Serial.println(F("Estado: Frio (Sin LED)"));
    // Todos los LEDs ya están apagados
  }
}