#include "kernel.h"


int update_vector_table(uint8_t vector_no, void *exception_handler)
{
    if( (vector_no < 2) ) return 0xff;

    // pfff....
    void **vector_address = (void *)((uint32_t)vector_no << 2);

    *vector_address = exception_handler;

    return 0;
}


uint8_t peekb(uint32_t address)
{
    return *(uint8_t *)address;
}


uint16_t peekw(uint32_t address)
{
    return *(uint16_t *)address;
}


uint32_t peekl(uint32_t address)
{
    return *(uint32_t *)address;
}


void pokeb(uint32_t address, uint8_t  byte)
{
    *(uint8_t *)address = byte;
}


void pokew(uint32_t address, uint16_t word)
{
    *(uint16_t *)address = word;
}


void pokel(uint32_t address, uint32_t lwrd)
{
    *(uint32_t *)address = lwrd;
}


uint8_t *memcpy(uint8_t *dest, const uint8_t *src, size_t count)
{
    for(uint32_t i=0; i<count; i++) dest[i] = src[i];
    return dest;
}


uint8_t *memset(uint8_t *dest, uint8_t val, size_t count)
{
    for(uint32_t i=0; i<count; i++) dest[i] = val;
    return dest;
}
