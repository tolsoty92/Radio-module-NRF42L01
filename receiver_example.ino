#include <Radio.h>
#include <SPI.h>             
#include <nRF24L01.h>        
#include <RF24.h> 

int msg[20];
int x1;
int x2;
int x3;
int x4;
int x5;
int x6;
TrR tr;

void setup()
{
  Serial.begin(9600);
  tr.begin();
  tr.startListening(0);
}

void loop()
{
  tr.receive(x1, x2, x3, x4, x5, x6);
  Serial.print(x1);
  Serial.print("\n");
  Serial.print(x2);
  Serial.print("\n");
  Serial.print(x3);
  Serial.print("\n");
  Serial.print(x4);
  Serial.print("\n");
  Serial.print(x5);
  Serial.print("\n");
  Serial.print(x6);
  Serial.print("\n");
}
