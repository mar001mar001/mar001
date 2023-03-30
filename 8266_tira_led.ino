
//unsigned long matrix[64] = {0x123456, 0x789abc, 0xdef012, 0x345678,
                            //0x9abcdef, 0x012345, 0x6789ab, 0xcdef01,
                            // ...resto de las palabras de 24 bits...
                           // };
unsigned long matrix[64] = {0x123456, 0x789abc};
int pin = 2;           // número del pin que se quiere definir como salida


unsigned long createWord(unsigned char byte1, unsigned char byte2, unsigned char byte3) {
  unsigned long word = 0;
  word |= ((unsigned long)byte1 << 16);  // combinar el valor del byte1 en los primeros 8 bits de la palabra
  word |= ((unsigned long)byte2 << 8);   // combinar el valor del byte2 en los siguientes 8 bits de la palabra
  word |= byte3;                         // combinar el valor del byte3 en los últimos 8 bits de la palabra
  return word;
}

void sendBit(int bit) {
  if (bit == 0) {
    digitalWrite(pin, HIGH);     // T0H
    delayMicroseconds(400);
    digitalWrite(pin, LOW);    // T0L
    delayMicroseconds(850);
  } else {
    digitalWrite(pin, HIGH);     // T1H
    delayMicroseconds(800);
    digitalWrite(pin, LOW);    // T1L
    delayMicroseconds(450);
  }
}

void sendWord(unsigned long word) {
  for (int i = 0; i < 24; i++) {
    int bit = (word >> i) & 1;  // obtener el bit en la posición i
    sendBit(bit);              // enviar el bit utilizando la función sendBit()
  }
}

void sendMatrix() {
  for (int i = 0; i < 64; i++) {
    unsigned long word = matrix[i];              // obtener la palabra de 24 bits en la posición i
    sendWord(word);                              // enviar los bits de la palabra utilizando la función sendWord()
  }
digitalWrite(pin, HIGH);
}

void setup() {
unsigned char byte1 = 100;
unsigned char byte2 = 200;
unsigned char byte3 = 50;
pinMode(pin, OUTPUT);  // definir el pin como salida

unsigned long word = createWord(byte1, byte2, byte3);  // crear la palabra utilizando la función createWord()

}

void loop() {
  // put your main code here, to run repeatedly:

}
