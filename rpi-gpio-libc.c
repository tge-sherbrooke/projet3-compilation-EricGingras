#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
	int gpio = atoi(argv[1]);
	char etat[1];
	char bufValue[30];
	char bufDirection[40];
	
	sprintf(bufValue, "/sys/class/gpio/gpio%d/value", gpio);
	sprintf(bufDirection, "/sys/class/gpio/gpio%d/direction", gpio);

	if(strcmp(argv[2], "on") == 0)
	{
		sprintf(etat, "%d", 1);
	}
	else if(strcmp(argv[2], "off") == 0)
	{
		sprintf(etat, "%d", 0);
	}
	else
	{
		printf("Invalid option");
	}


	int fd = open("/sys/class/gpio/export", O_WRONLY);

	write(fd, argv[1], strlen(argv[1]));

	close(fd);


	fd = open(bufDirection, O_WRONLY);

	write(fd, "out", 3);

	close(fd);



	fd = open(bufValue, O_WRONLY);

	write(fd, etat, 1);

	close(fd);

        return 0;

}
