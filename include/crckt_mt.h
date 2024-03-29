#ifndef __crckt_mt_h
#define __crckt_mt_h

/*
 * An implementation of the Mersenne Twister RNG, shamelessly stolen from
 * http://www.qbrundage.com/michaelb/pubs/essays/random_number_generation
 */

#include <stdlib.h>

#define MT_LEN       624

int mt_index;
unsigned long mt_buffer[MT_LEN];

#define MT_IA           397
#define MT_IB           (MT_LEN - MT_IA)
#define UPPER_MASK      0x80000000
#define LOWER_MASK      0x7FFFFFFF
#define MATRIX_A        0x9908B0DF
#define TWIST(b,i,j)    ((b)[i] & UPPER_MASK) | ((b)[j] & LOWER_MASK)
#define MAGIC(s)        (((s)&1)*MATRIX_A)

/*
 * initializes the mersenne twister generator for use.
 * this is a necessary step!
 */
void mt_init();

/* generates a random number with the mersenne twister algorithm */
unsigned long mt_random();

#endif // __crckt_mt_h
