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

## VDD_SDIO Regulator

This progam uses GPIO12 for connecting to the hdzero spi flash.
The same pin is used by the ESP32 to determine its internal flash's voltage.
To gurantee stable operation you might have to burn the appropiate efuse to force the correct voltage.
[See this page](https://docs.espressif.com/projects/esptool/en/latest/esp32s3/espefuse/index.html#setting-flash-voltage-vdd-sdio) for more information.