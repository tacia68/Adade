void Taskc  (void * pvParameters){
void escreve_temperatura_umidade_display(String temp_lida, String umid_lida);
  for(;;){
   enviarMedicao(); // Leitura e processamento do comando
   //escreve_temperatura_umidade_display(getLogTemperature(),  getLogHumidity());
   
   /*
   int ti = micros();

    while(micros() - ti < 500000){

    }

    Serial.println("Teste");*/

  }
  
}

void escreve_temperatura_umidade_display(String temp_lida, String umid_lida)
{
    char str_temp[10] = {0};
    char str_umid[10] = {0};

    /* formata para o display as strings de temperatura e umidade */
    sprintf(str_temp, "%s C", temp_lida);
    sprintf(str_umid, "%s ", umid_lida);
    
    display.clearDisplay();
    display.setCursor(0, OLED_LINE1);
    display.println("Temperatura:");
    display.setCursor(0, OLED_LINE2);
    display.println(str_temp);
    display.setCursor(0, OLED_LINE3);
    display.println("Umidade:");
    display.setCursor(0, OLED_LINE4);
    display.print(str_umid);
    display.display();
}
