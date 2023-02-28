#include <ESP8266WiFi.h>

const char* ssid = "MiRedWifi"; // Nombre de la red WiFi
const char* password = "contrasena"; // Contraseña de la red WiFi

const int interruptPin = 2; // Pin de interrupción externa

void setup() {
  pinMode(interruptPin, INPUT_PULLUP);
  WiFi.softAP(ssid, password); // Activar el punto de acceso WiFi
  attachInterrupt(digitalPinToInterrupt(interruptPin), interruptHandler, FALLING);
}

void loop() {
  // El loop del programa
}

void interruptHandler() {
  if (WiFi.getMode() == WIFI_AP) {
    // Si el modo WiFi es punto de acceso, desactivar el punto de acceso WiFi
    WiFi.softAPdisconnect();
  } else {
    // Si el modo WiFi no es punto de acceso, activar el punto de acceso WiFi
    WiFi.softAP(ssid, password);
  }
}
