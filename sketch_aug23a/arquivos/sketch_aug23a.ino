#include <DHT.h>

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

// ---------------DHT---Config------------
DHT dht(DHT_PIN, DHTTYPE);

void begin_dht(){
  pinMode(DHT_PIN, INPUT); 
  dht.begin();
  };
String getTemperature(){
  return TAG_RES + " " + TAG_TEM + " " + String(dht.readTemperature()*100,0)+"\n";
  };
String gethumidity(){
  return TAG_RES + " " + TAG_HUM + " " + String(dht.readHumidity()*100,0)+"\n";
  };
//-----ldr--config

class Ldr{
  int ldrpin;
  int lum;
  public:
  Ldr(int pin){
    ldrpin = pin;
    }
  int read(){
    lum = analogRead(ldrpin);
    return lum;
    }
  String getluminosity(){
    float luminosity = this->read()/4095.0;
    String lumi = String(luminosity*100,0);
    lumi.trim();
    return TAG_RES + " " + TAG_LDR + " " +lumi+"\n";
    }
    
  };
Ldr ldr(ANALOG_PIN_0);
String getluminosity(){
  return ldr.getluminosity();
  };

//-----processamento do comando
void processCommand(String command) {
    command.trim();
    command.toUpperCase();

    if (command == TAG_LDR){
      Serial.print(getluminosity());
    }

    else if (command == TAG_HUM){
      Serial.print(gethumidity());
    }
   
      
    
    else if (command == TAG_TEM){
      Serial.print(getTemperature());
    }
    
    else{
      Serial.print("ERR Unknown command.\n");
    }
      
}

//---Leitura da Serial----

void serialRead(){
    String serialCommand; // Strign responsavel por armazenar o comando

    while (Serial.available() > 0) {          // Serial.available() > 0 verifica se existe dados na porta serial
        char serialChar = Serial.read();      // Realiza a leitura de um bit na porta serial
        //Serial.print("Passou no Serial avaliable");
        serialCommand += serialChar;          // Concatena os bits lidos

        if (serialChar == '\n') {             // Verifica a quebra de linha para identificar o fim do comando
          //Serial.print("Passou no Serial char");
            processCommand(serialCommand);    // Função que processa o comando necessário e responde a ação
            serialCommand = "";               // Apaga o comando após o seu processamento
        }
    }
}

void setup() {
  Serial.begin(9600);
  Serial.printf("DBG Adade Initialized.\n");
  begin_dht();
}

void loop() {
  delay(100);   // Delay para não sobrecarregar o processador
  
  serialRead(); // Leitura e processamento do comando
}
