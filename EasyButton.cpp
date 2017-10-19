#include "EasyButton.h"

EasyButton::EasyButton(uint8_t pin, uint8_t activateSignal, bool internalPullup)
{
	if (internalPullup)
		pinMode(pin, INPUT_PULLUP);
	else
		pinMode(pin, INPUT);
	EasyButton::pin = pin;
	pressed = false;
	signal = activateSignal;
}

void EasyButton::work()
{
	if (digitalRead(pin) == signal)
	{
		if (pressed == false)
		{
			pressed = true;
			handle();
		}
	}
	else
		pressed = false;
}

void EasyButton::setButtonHandle(void (*fptr)(void))
{
	handle=fptr;
}