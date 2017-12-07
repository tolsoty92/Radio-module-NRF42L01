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
  tr.startWriting(0);
}

void loop()
{
  x1 = 1;
  x2 = 2;
  x3 = 33;
  x4 = 44;
  x5 = 555;
  x6 = 666;
  tr.transmitte(x1, x2, x3, x4, x5, x6);
}
