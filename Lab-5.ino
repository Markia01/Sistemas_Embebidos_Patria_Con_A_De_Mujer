#include <LiquidCrystal.h>
#include <DHT.h>

// --- CONFIGURACIÓN DEL LCD ---
// Pines: RS(12), E(11), D4(5), D5(4), D6(3), D7(2)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// --- CONFIGURACIÓN DEL SENSOR DHT ---
#define DHTPIN 7      // Pin digital donde conectaste el cable de DATOS del sensor
#define DHTTYPE DHT11 // Si tu sensor es BLANCO, cambia DHT11 por DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin(16, 2);
  dht.begin(); // Iniciar el sensor

  lcd.print("Iniciando...");
  delay(2000); // Esperar 2 seg a que el sensor arranque bien
}