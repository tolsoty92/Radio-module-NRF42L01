#ifndef Radio_h
#define Radio_h

#include "Arduino.h"
#include <SPI.h>             
#include <nRF24L01.h>        
#include <RF24.h> 
class TrR
{
	public:
		const int ce = 9;
		const int csn = 10;
		uint64_t pipes[10] = {0xF0F0F0F000, 0xF0F0F0F011, 0xF0F0F0F022, 0xF0F0F0F033, 0xF0F0F0F044, 0xF0F0F0F055};
		RF24 *radio;
		int msg[10];
		TrR();
		void begin();    
		void startListening(int pipe_num);
		void startWriting(int pipe_num);  
		void receive(int &x1, int &x2, int &x3, int &x4, int &x5, int &x6);
		void transmitte(int x1, int x2, int x3, int x4, int x5, int x6);
};
#endif
