//
//
//

#include "DAC.h"
#include "Util.h"

void DACClass::init()
{
}

void DACClass::print(unsigned int value, int maximumPin, int minimumPin)
{
	for (int i = maximumPin; i >= minimumPin; i--)
	{
		int o = bitRead(value, i - minimumPin);
		//Serial.print(o);
		//Serial.print("");
		digitalWrite(i, o);
	}
}
boolean DACClass::switchVal(String msg)
{
	boolean go = false;
	if (msg.compareTo("") == 0) return go;
	String newMsg = msg.substring(1);
	if (msg[0] == 'C')
	{
		IsWave = false;
		IsSquare = false;
		IsConstant = true;
		Out = newMsg.toFloat();
	}
	else if (msg[0] == 'W')
	{
		IsWave = true;
		IsSquare = false;
		IsConstant = false;
		Out = newMsg.toFloat();
	
	}
	else if (msg[0] == 'Q')
	{
		IsWave = false;
		IsSquare = true;
		IsConstant = false;
		Out = newMsg.toFloat();
	}

	return go;
}
void DACClass::reasignaT(int amplitude)
{
	if (T >= amplitude)
	{
		k = -1;
	}
	else if (T <= (-1 * amplitude) && k == -1)
	{
		k = 1;
	}
	T += k;
}
void DACClass::prepare(int maximumPin, int minimumPin)
{
	for (int i = maximumPin; i >= minimumPin; i--)
	{
		pinMode(i, OUTPUT);
		digitalWrite(i, LOW);
	}
}
unsigned int DACClass::sino(float amplitude, float freqTune, int count, boolean cosino)
{
	float Tdiv = (float)count * 2 / maxNumber;
	float arg = Tdiv * Pi2 * freqTune;
//	(float*) dele * = (float);
	//dele = sin;
	float element = amplitude;
	if (cosino) element*=cos(arg);
	else element *= sin(arg);
	element += amplitude;
	unsigned int newElement = round(element) + 1;
	return newElement;
}
unsigned int DACClass::ramp(float amplitude, float freqTune, int count)
{
	float Tdiv = (float)count * 2 / maxNumber;
//	float arg = Tdiv * Pi2 * freqTune;
	//	(float*) dele * = (float);
	//dele = sin;
	float element = amplitude*Tdiv*freqTune;
//	else element *= sin(arg);
	element += amplitude;
	unsigned int newElement = round(element) + 1;
	return newElement;
}
DACClass DAC;