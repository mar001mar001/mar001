#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

// Declaración de funciones
void tarea_nucleo_0(void *parametro);
void tarea_nucleo_1(void *parametro);

void setup() {
  Serial.begin(9600);

  // Crear tarea para el núcleo 0
  xTaskCreatePinnedToCore(
    tarea_nucleo_0,   // Función de tarea
    "Tarea núcleo 0", // Nombre de tarea
    10000,            // Tamaño de la pila
    NULL,             // Parámetros de tarea
    1,                // Prioridad de tarea
    NULL,             // Handle de tarea
    0                 // Núcleo de ejecución
  );

  // Crear tarea para el núcleo 1
  xTaskCreatePinnedToCore(
    tarea_nucleo_1,   // Función de tarea
    "Tarea núcleo 1", // Nombre de tarea
    10000,            // Tamaño de la pila
    NULL,             // Parámetros de tarea
    1,                // Prioridad de tarea
    NULL,             // Handle de tarea
    1                 // Núcleo de ejecución
  );
}

void loop() {
  // El loop del programa principal
}

void tarea_nucleo_0(void *parametro) {
  while (true) {
    Serial.println("Tarea núcleo 0");
    delay(1000);
  }
}

void tarea_nucleo_1(void *parametro) {
  while (true) {
    Serial.println("Tarea núcleo 1");
    delay(500);
  }
}
