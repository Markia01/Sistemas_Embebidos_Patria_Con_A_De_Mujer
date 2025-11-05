#include "DHT.h"

// --- Definiciones de Pines ---
#define DHTPIN 2          // Pin de datos del DHT11
#define DHTTYPE DHT11     // Tipo de sensor
#define BOTON_PIN 3       // Pin del botón de inicio
#define LED_VERDE_PIN 7
#define LED_AMARILLO_PIN 8
#define LED_ROJO_PIN 9

// Inicializa el objeto sensor
DHT dht(DHTPIN, DHTTYPE);

// --- Variables Globales ---
// Guardamos el estado anterior del botón para detectar CADA "click"
int ultimoEstadoBoton = HIGH; // HIGH (suelto) por el INPUT_PULLUP

void setup() {
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