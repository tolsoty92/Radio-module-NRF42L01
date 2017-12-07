#include "Radio.h"
#include <SPI.h>             
#include <nRF24L01.h>        
#include <RF24.h>   

TrR::TrR(){}

void TrR::begin(int pipe_num)
	/* =========================================
	Функция, предназначена для инициализации
	работы радиомодуля.
	В качестве аргумента принимает номер трубы (0-5).	
	===========================================*/
	
{
  radio = new RF24(ce, csn);  					// Номера пинов, подключаемых к ce и csn выходам радиомодуля
  radio->begin();                               //  Начало работы      
  radio->setChannel(0x55);    					// Номер канала связи                           
  radio->setDataRate     (RF24_1MBPS);   		// Скорость передачи данных                
  radio->setPALevel      (RF24_PA_HIGH);    	// Мощность работы радиомодуля            
  radio->openReadingPipe (0, pipes[pipe_num]);	// Открытие трубы
}

void TrR::startListening()
	/* =========================================
	Функция запускает решим приема данных.	
	===========================================*/
	
{
  radio->startListening();
}

void TrR::stopListening()
	/* =========================================
	Функция останавливает решим приема данных.	
	===========================================*/
{
  radio->stopListening();
}

void TrR::receive(int &x1, int &x2, int &x3, int &x4, int &x5, int &x6)
  /* ===================================
  Функция принимает 6 числовых переменных и 
  записывает в них принятые радиомодулем значения.
  Если передача данных не осуществляется, выводит 
  сообщение 'Radio is not available'.
  ======================================*/
  
{
  if(radio->available())
     {
  radio->read(&msg, sizeof(msg));
  x1 = msg[0];
  x2 = msg[1];
  x3 = msg[2];
  x4 = msg[3];
  x5 = msg[4];
  x6 = msg[5]}
  else{
  Serial.print('Radio is not available\n');}
}

void TrR::transmitte(int x1, int x2, int x3, int x4, int x5, int x6)
  /* ===================================
  Функция принимает 6 числовых переменных и 
  осуществляет их передачу.
  ======================================*/
  
{
  msg[0] = x1;
  msg[1] = x2;
  msg[2] = x3;
  msg[3] = x4;
  msg[4] = x5;
  msg[5] = x6;
  radio->write(&msg, sizeof(msg));
}	






