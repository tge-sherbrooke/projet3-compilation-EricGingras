#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "gpio.h"


void set_gpio(int pin, char *etat)
{
	char gpio[3];
	char etatVar[3];
	char bufValue[30];
	char bufDirection[40];

	sprintf(bufValue, "/sys/class/gpio/gpio%d/value", pin);
	sprintf(bufDirection, "/sys/class/gpio/gpio%d/direction", pin);
	sprintf(gpio, "%d", pin);

	if(strcmp(etat, "on") == 0)
	{
		sprintf(etatVar, "%d", 1);
	}
	else if(strcmp(etat, "off") == 0)
	{
		sprintf(etatVar, "%d", 0);
	}
	else
	{
		printf("Invalid option");
	}


	int fd = open("/sys/class/gpio/export", O_WRONLY);

	write(fd, gpio, strlen(gpio));

	close(fd);


	fd = open(bufDirection, O_WRONLY);

	write(fd, "out", 3);

	close(fd);



	fd = open(bufValue, O_WRONLY);

	write(fd, etatVar, 1);

	close(fd);

}
