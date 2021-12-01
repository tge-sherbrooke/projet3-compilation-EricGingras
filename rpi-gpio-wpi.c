#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <string.h>


int main(int argc, char *argv[])
{
	int pin = atoi(argv[1]);
	wiringPiSetup();
	pinMode(pin, OUTPUT);

	if(strcmp(argv[2], "on") == 0)
	{ 
		digitalWrite(pin, HIGH);
		printf("On: %d \n\r", pin);
	}
	else if(strcmp(argv[2], "off") == 0)
	{
		digitalWrite(pin, LOW);
		printf("Off: %d \n\r", pin);
	}


	return 0;

}
