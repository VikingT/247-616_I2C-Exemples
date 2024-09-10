#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

// Function prototypes for main.c
int fdPortI2C;  // file descriptor I2C

#endif // MAIN_H
