#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

#define MSB 15
#define LSB 0

unsigned 
get_bit(uint16_t x, unsigned n)
{
    // YOUR CODE HERE
    unsigned res = 1 << n;
    res &=  x;
    res >>= n;
    return res;
}

void 
set_bit(uint16_t * x, unsigned n, unsigned v) 
{
    // YOUR CODE HERE
    uint16_t tmp1 = 1 << n;
    uint16_t tmp2 = v << n;
    (*x) &= ~tmp1;
    (*x) |= tmp2;
}

void 
lfsr_calculate(uint16_t *reg) 
{
    /* YOUR CODE HERE */
    unsigned tmp = 0;
    tmp ^= get_bit(*reg, LSB + 0);
    tmp ^= get_bit(*reg, LSB + 2);
    tmp ^= get_bit(*reg, LSB + 3);
    tmp ^= get_bit(*reg, LSB + 5);
    
    (*reg) >>= 1;
    set_bit(reg, MSB, tmp);
}

