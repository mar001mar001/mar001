#include <Ticker.h>

const byte PIN_R = 2; // LED AZUL, se puede cambiar por la salida GPIO 0
const byte PIN_S = 1; // TX
const byte PIN_T = 3; // RX

const byte ESTADOS[][3] = {
 //R-0  S-1   T-2
  {HIGH, LOW, HIGH},   // Estado 1   0   101 A
  {HIGH, LOW, LOW},    // Estado 2   1   100 B
  {HIGH, HIGH, LOW},   // Estado 3   2   110 C
  {LOW, HIGH, LOW},    // Estado 4   3   010 D
  {LOW, HIGH, HIGH},   // Estado 5   4   011 E
  {LOW, LOW, HIGH}     // Estado 6   5   001 F
};
const byte NUM_ESTADOS = sizeof(ESTADOS) / sizeof(ESTADOS[0]);

volatile byte indice = 0;
Ticker timer1;

void setup() {
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_S, OUTPUT);
  pinMode(PIN_T, OUTPUT);

  timer1.attach_ms(3.333333333, funcion_timer1);
}

void loop() {
  // El loop del programa
}

void funcion_timer1() {
  digitalWrite(PIN_R, ESTADOS[indice][0]);
  digitalWrite(PIN_S, ESTADOS[indice][1]);
  digitalWrite(PIN_T, ESTADOS[indice][2]);
  indice = (indice + 1) % NUM_ESTADOS;

}
