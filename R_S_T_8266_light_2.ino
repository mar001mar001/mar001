#include <Ticker.h>

const byte PIN_R = 1; // TX
const byte PIN_S = 2; // LED AZUL, se puede cambiar por la salida GPIO 0
const byte PIN_T = 3; // RX

const byte NUM_ESTADOS = 3;
const byte ESTADOS[NUM_ESTADOS] = {PIN_T, PIN_S, PIN_R};

volatile byte indice = 0;
bool estado_actual[NUM_ESTADOS] = {true, false, true}; // Estado inicial de cada pin

Ticker timer1;

void setup() {
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_S, OUTPUT);
  pinMode(PIN_T, OUTPUT);
  digitalWrite(PIN_R, estado_actual[2]);
  digitalWrite(PIN_S, estado_actual[1]);
  digitalWrite(PIN_T, estado_actual[0]);
  timer1.attach_ms(3.333333333, funcion_timer1);
}

void loop() {
  // El loop del programa
}

void funcion_timer1() {
  estado_actual[indice] = !estado_actual[indice];
  digitalWrite(ESTADOS[indice], estado_actual[indice]);
  indice = (indice + 1) % NUM_ESTADOS;
}
