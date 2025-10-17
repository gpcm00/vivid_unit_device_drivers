# Purpose

This module just prepares the SPI2 bus to be binded with SPIDEV device driver found in the kernel's source code at drivers/spi/spidev.c

You still need to compile the spidev files yourself and load it manually after loading this module. Just for some reason, Vivid Unit's original DT didn't load it by default.