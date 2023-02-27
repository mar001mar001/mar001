#include <Ticker.h>

const byte PIN_R = 1; // TX
const byte PIN_S = 2; // LED AZUL, se puede cambiar por la salida GPIO 0
const byte PIN_T = 3; // RX

const byte ESTADOS[6][2] = {// del 0 al 5 y del 0 al 1
 //R-1  S-2   T-3
  {3,0}, // Estado 1   0   101 A   3,0
  {2,1}, // Estado 2   1   100 B   2,1
  {1,0}, // Estado 3   2   110 C   1,0
  {3,1}, // Estado 4   3   010 D   3,1
  {2,0}, // Estado 5   4   011 E   2,0
  {1,1}  // Estado 6   5   001 F   1,1
};
const byte NUM_ESTADOS = sizeof(ESTADOS) / sizeof(ESTADOS[0]);

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
  digitalWrite(ESTADOS[indice][0], ESTADOS[indice][1]);
  indice = (indice + 1) % 6;
}
