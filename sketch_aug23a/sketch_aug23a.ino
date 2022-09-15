#include "DHT.h"

//------------------- Definição dos parâmetros do DHT
#define DHTTYPE DHT11 // Dht utilizado
#define DHT_PIN 13    // Pino do DHT


//-------------------- Definição do LDR
#define ANALOG_PIN_0 36
//---------------------TAG dos comandos
String TAG_TEM = "GET_TEM"; // Tag da temperatura
String TAG_HUM = "GET_HUM"; // Tag da umidade
String TAG_LDR = "GET_LDR"; // Tag do ldr
String TAG_RES = "RES";     // TAG de resposta

void setup() {
  Serial.begin(9600);
  Serial.printf("DBG Adade Initialized.\n");
  begin_dht();
}

void loop() {
  delay(100);   // Delay para não sobrecarregar o processador
  
  serialRead(); // Leitura e processamento do comando
}
