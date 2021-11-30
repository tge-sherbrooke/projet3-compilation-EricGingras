#include "gpio.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
	set_gpio(atoi(argv[1]), argv[2]);

	return 0;

}
