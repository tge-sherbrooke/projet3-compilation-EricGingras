CC=gcc
CFLAGS=-I.

%.o: %.c main.h
	$(CC) -c -o $@ $< $(CFLAGS)

wpi: main.o gpio-wpi.o
	$(CC) -o rpi-gpio.wpi main.o rpi-gpio-wpi.o -lwiringPi							

libc: main.o gpio-libc.o
	$(CC) -o rpi-gpio.libc main.o rpi-gpio-libc.o
