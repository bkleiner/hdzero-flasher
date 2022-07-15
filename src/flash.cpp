#include "flash.h"

#include <SerialFlash.h>

const char *flash_part_number(const uint8_t *id)
{
    if (id[0] == 0xEF)
    {
        // Winbond
        if (id[1] == 0x40)
        {
            if (id[2] == 0x14)
                return "W25Q80BV";
            if (id[2] == 0x15)
                return "W25Q16DV";
            if (id[2] == 0x17)
                return "W25Q64FV";
            if (id[2] == 0x18)
                return "W25Q128FV";
            if (id[2] == 0x19)
                return "W25Q256FV";
        }
    }
    if (id[0] == 0x01)
    {
        // Spansion
        if (id[1] == 0x02)
        {
            if (id[2] == 0x16)
                return "S25FL064A";
            if (id[2] == 0x19)
                return "S25FL256S";
            if (id[2] == 0x20)
                return "S25FL512S";
        }
        if (id[1] == 0x20)
        {
            if (id[2] == 0x18)
                return "S25FL127S";
        }
    }
    if (id[0] == 0xC2)
    {
        // Macronix
        if (id[1] == 0x20)
        {
            if (id[2] == 0x18)
                return "MX25L12805D";
        }
    }
    if (id[0] == 0x20)
    {
        // Micron
        if (id[1] == 0xBA)
        {
            if (id[2] == 0x20)
                return "N25Q512A";
            if (id[2] == 0x21)
                return "N25Q00AA";
        }
        if (id[1] == 0xBB)
        {
            if (id[2] == 0x22)
                return "MT25QL02GC";
        }
    }
    if (id[0] == 0xBF)
    {
        // SST
        if (id[1] == 0x25)
        {
            if (id[2] == 0x02)
                return "SST25WF010";
            if (id[2] == 0x03)
                return "SST25WF020";
            if (id[2] == 0x04)
                return "SST25WF040";
            if (id[2] == 0x41)
                return "SST25VF016B";
            if (id[2] == 0x4A)
                return "SST25VF032";
        }
        if (id[1] == 0x25)
        {
            if (id[2] == 0x01)
                return "SST26VF016";
            if (id[2] == 0x02)
                return "SST26VF032";
            if (id[2] == 0x43)
                return "SST26VF064";
        }
    }
    if (id[0] == 0x1F)
    {
        // Adesto
        if (id[1] == 0x89)
        {
            if (id[2] == 0x01)
                return "AT25SF128A";
        }
    }
    return "(unknown chip)";
}

flash_status flash_erase(uint32_t address)
{
    SerialFlash.eraseAll();
    return FLASH_OK;
}

flash_status flash_write(uint32_t address, uint32_t *data, uint32_t length)
{
    SerialFlash.write(address, data, length);
    return FLASH_OK;
}