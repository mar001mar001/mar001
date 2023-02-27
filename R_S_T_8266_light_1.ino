#include <Ticker.h>

const byte PIN_R = 1; // TX
const byte PIN_S = 2; // LED AZUL, se puede cambiar por la salida GPIO 0
const byte PIN_T = 3; // RX


const byte ESTADOS [3] = {3,2,1};// del 0 al 5 y del 0 al 1
 //R-1  S-2   T-3

volatile byte indice = 0;
Ticker timer1;

void setup() {
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_S, OUTPUT);
  pinMode(PIN_T, OUTPUT);
  digitalWrite(PIN_R, 1);//condicion inicial R
  digitalWrite(PIN_S, 0);//condicion inicial S
  digitalWrite(PIN_T, 1);//condicion inicial T
  timer1.attach_ms(3.333333333, funcion_timer1);
}

void loop() {
  // El loop del programa
}

void funcion_timer1() {
  digitalWrite(ESTADOS[indice], !digitalRead(ESTADOS[indice]));
  indice = (indice + 1) % 3;
}
