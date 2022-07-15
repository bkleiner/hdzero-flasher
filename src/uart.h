#pragma once

#include <stdint.h>

// adapted from https://github.com/ferenc-nemeth/stm32-bootloader/blob/master/Inc/uart.h

/* Timeout for HAL. */
#define UART_TIMEOUT 1000

/* Status report for the functions. */
typedef enum
{
    UART_OK = 0x00u,   /**< The action was successful. */
    UART_ERROR = 0xFFu /**< Generic error. */
} uart_status;

uart_status uart_receive(uint8_t *data, uint16_t length);
uart_status uart_transmit_str(uint8_t *data);
uart_status uart_transmit_ch(uint8_t data);