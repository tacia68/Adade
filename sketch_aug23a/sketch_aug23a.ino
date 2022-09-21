
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
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

/* Endereço I2C do display */
#define OLED_ADDR 0x3c

/* distancia, em pixels, de cada linha em relacao ao topo do display */
#define OLED_LINE1 0
#define OLED_LINE2 10
#define OLED_LINE3 20
#define OLED_LINE4 30
#define OLED_LINE5 40
#define OLED_LINE6 50

/* Configuração da resolucao do display (este modulo possui display 128x64) */
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

/* objeto do display */
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, 16);

/*Temperatura e humidade*/
float temp = 0;
float humi = 0;


TaskHandle_t Task_read_write;
TaskHandle_t Task_conexao;

void setup() {
  Serial.begin(9600);
  Serial.printf("DBG Adade Initialized.\n");
  begin_dht();
  connect_wifi();
/* inicializa display OLED
   Wire.begin(4, 15);
   
   if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR))
       Serial.println("Display OLED: falha ao inicializar");
   else
   {
       Serial.println("Display OLED: inicializacao ok");
       display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
       /* Limpa display e configura tamanho de fonte 
       display.clearDisplay();
       display.setTextSize(1);
       display.setTextColor(WHITE);
   }  
*/
   //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
                    Taskrw,             /* Task function. */
                    "Task_read_write",     /* name of task. */
                    10000,                 /* Stack size of task */
                    NULL,                  /* parameter of the task */
                    1,                     /* priority of the task */
                    &Task_read_write,                /* Task handle to keep track of created task */
                    1);                    /* pin task to core 0 */                  
 
  //create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
                    Taskc,   /* Task function. */
                    "Task_conexao",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task_conexao,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 1 */
}

void loop() {
  disableCore0WDT();
}
