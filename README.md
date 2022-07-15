# hdzero-flasher

Simple ESP32 based hdzero flasher.

Wire the ESP32 to the HDZERO Flasher plug:
```
VTX          COLOR     ESP32
3.3V         RED       3.3V
GND          BLACK     GND
SPI CS       YELLOW    GPIO15
SPI CLK      GREEN     GPIO14
SPI DI       BLUE      GPIO12
SPI DIO      WHITE     GPIO13
RTSN_5680    ORANGE    GPIO4
```

Firmware implements the XMODEM protocol.
A python script to send data is included. 