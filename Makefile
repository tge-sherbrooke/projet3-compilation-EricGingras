CC=gcc
CFLAGS=-I.

%.o: %.c main.h
	$(CC) -c -o $@ $< $(CFLAGS)

wpi: main.o gpio-wpi.o
	$(CC) -o wpi main.o gpio-wpi.o -lwiringPi

libc: main.o gpio-libc.o
	$(CC) -o libc main.o gpio-libc.o
