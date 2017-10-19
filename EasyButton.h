#ifndef EasyButton_h
#define EasyButton_h

#include "Arduino.h"

class EasyButton
{
	bool pressed;
	uint8_t signal;
	uint8_t pin;
	void (*handle)(void);
public:
	EasyButton(uint8_t pin, uint8_t activateSignal, bool internalPullup);
	void work();
	void setButtonHandle(void (*fptr)(void));


	/* data */
};
#endif