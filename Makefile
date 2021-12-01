#!/bin/bash

CC=gcc
CFLAGS=-I.

%.o: %.c main.h
	$(CC) -c -o $@ $< $(CFLAGS)

wpi: main.o gpio-wpi.o
	$(CC) -o rpi-gpio main.o gpio-wpi.o -lwiringPi

libc: main.o gpio-libc.o
	$(CC) -o rpi-gpio main.o gpio-libc.o
