#ifndef __crckt_physics_h
#define __crckt_physics_h

#include <math.h>

/* 
 * given a sample rate, converts a time (in seconds) to a number of 
 * digital samples.
 */
unsigned long int discretize(unsigned long int sample_rate, 
			     float time_interval);

/*
 * given a sample rate, returns the time interval between ticks as
 * as a floating point number.
 */
float delta_ticks(unsigned long int sample_rate);

#endif // __crckt_physics_h
