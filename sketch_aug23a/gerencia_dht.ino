#include "DHT.h"
DHT dht(DHT_PIN, DHTTYPE);

void begin_dht(){
  pinMode(DHT_PIN, INPUT); 
  dht.begin();
  };
String getTemperature(){
  return TAG_RES + " " + TAG_TEM + " " + String(temp,0)+"\n";
  };
String gethumidity(){
  return TAG_RES + " " + TAG_HUM + " " + String(humi,0)+"\n";
  };

String getLogTemperature(){
  temp = dht.readTemperature()*100; // Atualiza temperatura
return String(temp,0);
}

String getLogHumidity(){
  humi = dht.readHumidity()*100; // Atualiza humidade
return String(humi,0);
}
