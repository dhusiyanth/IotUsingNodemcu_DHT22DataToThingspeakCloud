#include<WiFi.h>
#include<DHT.h>
#define DHTPIN  27
#define DHTTYPE  DHT22
DHT dht(DHTPIN,DHTTYPE);
WiFiClient client;
char server[]="api.thinkspeak.com ";
void setup()
{
 Serial.begin(115200);
 dht.begin(); 
 WiFi.mode(WIFI_STA);
 WiFi.begin("DHUSIYANTH","14122003");
 Serial.print("connecting");
 
 while(WiFi.status() != WL_CONNECTED)
 {
  Serial.print(".");
  delay(1000);
 }
 
 Serial.println("Successfully connected to network");
 Serial.println(WiFi.localIP());

}
void loop()
{
  float temperaturee = dht.readTemperature();
  float humidityy = dht.readHumidity();

  client.stop();

  if(client.connect(server,80))
  {
  client.println("GET https://api.thingspeak.com/update?api_key=TOI0ED7Q605ADLO3&field1=" + String(temperaturee) + "&field2=" + String(humidityy));
  
  }
  delay(10000);
}
