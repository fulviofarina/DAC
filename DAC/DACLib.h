// DAC.h

#ifndef _DACLIB_h
#define _DACLIB_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <math.h>
#define maxPin 13
#define minPin  4
#define Pi2  2*3.1415
#define maxNumber  1023
#define divider maxNumber/2

class DACClass
{
protected:



public:
	int T = 0;
	int k = 1;
	unsigned int Out = 0;
	bool IsWave = true;
	bool IsSquare = false;
	bool IsTriang = false;
	bool IsConstant = false;

	float freqTune = 1.2;
	void init();
	void print(unsigned int value, int maximumPin, int minimumPin);
	boolean switchVal(String msg);
	void reasignaT(int amplitude);
	void prepare(int maximumPin, int minimumPin);
	unsigned int sino(float amplitude, float freqTune, int count, boolean cosino = false);
	unsigned int ramp(float amplitude, float freqTune, int count);

};

extern DACClass DAC;

#endif
