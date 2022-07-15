#pragma once

#include <stdint.h>

#define FLASH_APP_START_ADDRESS 0x0
#define FLASH_APP_END_ADDRESS 0x10000

/* Status report for the functions. */
typedef enum
{
    FLASH_OK = 0x00u,             /**< The action was successful. */
    FLASH_ERROR_SIZE = 0x01u,     /**< The binary is too big. */
    FLASH_ERROR_WRITE = 0x02u,    /**< Writing failed. */
    FLASH_ERROR_READBACK = 0x04u, /**< Writing was successful, but the content of the memory is wrong. */
    FLASH_ERROR = 0xFFu           /**< Generic error. */
} flash_status;

flash_status flash_erase(uint32_t address);
flash_status flash_write(uint32_t address, const uint8_t *data, uint32_t length);

const char *flash_part_number(const uint8_t *id);