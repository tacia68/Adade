
void Taskrw (void * pvParameters){
  for(;;){
    int ti = micros();

    while(micros() - ti < 100000){
    }
    leituraSerial(); // Leitura e processamento do comando
    /*

    while ( isnan(temp) || isnan(humi) ) {
      Serial.println("Erro ao ler sensor DHT22!");
      temp = dht.readTemperature()*100; // Atualiza temperatura
      humi = dht.readHumidity()*100; // Atualiza humidade
      ti = micros();
      while(micros() - ti < 1000000){}
        temp = dht.readTemperature()*100; // Atualiza temperatura
        humi = dht.readHumidity()*100; // Atualiza humidade    
    }

    Serial.println(temp);
    Serial.println(humi);
    */
  }
}