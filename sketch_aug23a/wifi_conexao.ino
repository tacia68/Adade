//WiFi----------------------
#include <WiFi.h>
#include <HTTPClient.h>
//Config-----------------------------------------------------------
const char* ssid        = "LabMat";
const char* password    = "Rietveld@123";

char *server = "script.google.com";  // Server URL

char *GScriptId = "AKfycbwzQ11wdnsAQAT4eaV1tR40y9W1LwDJ6RoaoMerJ371EfBJ1y2k7pNrym-IIfY_K2fpuQ"; //planilha teste

                
const int httpsPort = 443;

WiFiClientSecure client;

long tempoEnvio = 0;

void connect_wifi(void)
{
  
  Serial.print("DBG Connecting to wifi: ");
  Serial.println(ssid);
  Serial.flush();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
  
    delay(500);
    Serial.print(WiFi.status());
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("DBG WiFi connected");
  Serial.println("DBG IP address: ");
  Serial.println(WiFi.localIP());
}

void enviarMedicao()
{
  HTTPClient http;

  tempoEnvio = millis() - tempoEnvio;
  String tem = getLogTemperature();
  String hum = getLogHumidity();
  String ldr = getLogLuminosity();
  while ( isnan(temp) || isnan(humi) ) {
    int ti = micros();
    while(micros() - ti < 100000 && micros() - ti > 0){}
    String tem = getLogTemperature();
    String hum = getLogHumidity();
    String ldr = getLogLuminosity();
  }
  String url = String("https://script.google.com") + "/macros/s/" + GScriptId + "/exec?" + "value1=" + tem + "&value2=" + hum + "&value3=" + ldr;
  tempoEnvio = millis();
  
  Serial.print("DBG: Making a request");
  http.begin(url.c_str()); //Specify the URL and certificate
  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
  int httpCode = http.GET();
  String payload;
  if (httpCode > 0) { //Check for the returning code
    payload = http.getString();

    Serial.println(httpCode);
    Serial.println(payload);
    //     testdrawstyles(payload);
    //if (httpCode == 200 or httpCode == 201) tempPing.Saida(0);
  }
  else {
    Serial.println("DBG: Error on HTTP request");
  }
  http.end();

}
