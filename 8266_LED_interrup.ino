// Definimos las constantes para los pines del interruptor y el LED
const int interruptorPin = 2; // Puedes usar cualquiera de los pines GPIO disponibles
const int ledPin = 13; // Puedes cambiarlo por cualquier otro pin que tenga un LED conectado

// Variables para almacenar el estado actual del interruptor y del LED
volatile boolean interruptorEstado = LOW;
boolean ledEstado = LOW;

void setup() {
  // Configuramos el pin del interruptor como entrada y activamos la resistencia pull-up interna
  pinMode(interruptorPin, INPUT_PULLUP);
  // Configuramos el pin del LED como salida
  pinMode(ledPin, OUTPUT);

  // Configuramos la interrupción externa para que se active en el cambio de estado del interruptor
  attachInterrupt(digitalPinToInterrupt(interruptorPin), interruptorCambio, CHANGE);
}

void loop() {
  // No hacemos nada en el loop, ya que todo se maneja a través de la interrupción externa
}

// Función que se ejecuta cuando cambia el estado del interruptor
void interruptorCambio() {
  // Obtenemos el nuevo estado del interruptor
  interruptorEstado = digitalRead(interruptorPin);

  // Si el interruptor está activado
  if (interruptorEstado == HIGH) {
    // Encendemos el LED
    digitalWrite(ledPin, HIGH);
    ledEstado = HIGH;
  } else {
    // Apagamos el LED
    digitalWrite(ledPin, LOW);
    ledEstado = LOW;
  }
}
