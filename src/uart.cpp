#include "uart.h"

#include <Arduino.h>

uart_status uart_receive(uint8_t *data, uint16_t length)
{
    uint32_t start = millis();

    uint16_t read = 0;
    while (read < length)
    {
        if (millis() - start > UART_TIMEOUT)
        {
            return UART_ERROR;
        }
        if (!Serial.available())
        {
            continue;
        }

        data[read] = Serial.read();
        start = millis();
        read++;
    }

    return UART_OK;
}

uart_status uart_transmit_str(uint8_t *data)
{
    Serial.write((const char *)data);
    Serial.flush();
    return UART_OK;
}

uart_status uart_transmit_ch(uint8_t data)
{
    Serial.write(data);
    Serial.flush();
    return UART_OK;
}