#include "DHT.h"
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
