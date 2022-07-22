#include <SPI.h>
#include <Arduino.h>
#include <SerialFlash.h>

#include "flash.h"
#include "xmodem.h"

/* HDZERO Pinout
1 3.3V
2 ground
3 SPI CS
4 SPI CLK
5 SPI DI
6 SPI DIO
7 RTSN_5680
*/

#define RESET_PIN 2
#define CS_PIN 15

bool spi_is_init = false;
SPIClass FLASH_SPI_PORT(HSPI);

void setup()
{
  pinMode(RESET_PIN, OUTPUT);

  Serial.begin(115200);
}

void spi_init()
{
  if (spi_is_init)
  {
    return;
  }

  digitalWrite(RESET_PIN, LOW);
  delay(10);

  FLASH_SPI_PORT.setFrequency(10000000);
  SerialFlash.begin(FLASH_SPI_PORT, CS_PIN);
  spi_is_init = true;
}

void print_chip_info()
{
  uint8_t id[64];
  SerialFlash.readID(id);
  Serial.print(F("JEDEC ID: "));
  Serial.print(id[0], HEX);
  Serial.print(' ');
  Serial.print(id[1], HEX);
  Serial.print(' ');
  Serial.println(id[2], HEX);

  Serial.print(F("Part Number: "));
  Serial.println(flash_part_number(id));

  Serial.print(F("Memory Size: "));
  const uint32_t chipsize = SerialFlash.capacity(id);
  Serial.print(chipsize);
  Serial.println(F(" bytes"));

  Serial.print(F("Block Size: "));
  const uint32_t blocksize = SerialFlash.blockSize();
  Serial.print(blocksize);
  Serial.println(F(" bytes"));
}

void loop()
{
  while (Serial.available() == 0)
  {
    delay(1);
  }

  const uint8_t input = Serial.read();
  switch (input)
  {
  case 'p':
    spi_init();
    print_chip_info();
    break;

  case 'f':
    spi_init();
    xmodem_receive();
    // Fallthrough
    break;

  case 'e':
    Serial.println("Exiting...");
    spi_is_init = false;
    FLASH_SPI_PORT.end();
    delay(10);

    digitalWrite(RESET_PIN, HIGH);
    break;

  default:
    Serial.printf("Unknown command %c\r\n", input);
    break;
  }
}
