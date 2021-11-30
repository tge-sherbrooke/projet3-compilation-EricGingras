#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <string.h>
#include "gpio.h"

void set_gpio(int pin, char *etat)
{
	wiringPiSetup();
	pinMode(pin, OUTPUT);

	if(strcmp(etat, "on") == 0)
	{
		digitalWrite(pin, HIGH);
		printf("On: %d \n\r", pin);
	}
	else if(strcmp(etat, "off") == 0)
	{
		digitalWrite(pin, LOW);
		printf("Off: %d \n\r", pin);
	}

}
