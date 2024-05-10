#include <stdio.h>
#include "bit_ops.h"

/* You may only use bitwise operations such as and (&), 
   or (|), xor (^), not (~), left shifts («), and right
   shifts (»). You may not use any for/while loops or 
   conditional statements. You also may not use modulo(%), 
   division, addition subtraction, or multiplication for 
   this question. 
*/

// Return the nth bit of x.
// Assume 0 <= n <= 31
unsigned 
get_bit(unsigned x, unsigned n)
{
    // YOUR CODE HERE
    unsigned res = 1 << n;
    res &=  x;
    res >>= n;
    return res;
}

// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void 
set_bit(unsigned * x, unsigned n, unsigned v) 
{
    // YOUR CODE HERE
    unsigned tmp1 = 1 << n;
    unsigned tmp2 = v << n;
    (*x) &= ~tmp1;
    (*x) |= tmp2;
}

// Flip the nth bit of the value of x.
// Assume 0 <= n <= 31
void 
flip_bit(unsigned * x, unsigned n) 
{
    // YOUR CODE HERE
    unsigned tmp = 1 << n;
    (*x) ^= tmp;
}
