#ifndef __crckt_exp_h
#define __crckt_exp_h

#include <math.h>
#include <limits.h>
#include "crckt_mt.h"

/* 
 * generates random numbers from an exponential distribution with
 * rate parameter lambda in Hz.  it is discretized, so it needs to
 * know sample rate as well.  it returns an integer number of samples.
 */

unsigned long int crckt_exp_draw(const unsigned long int sample_rate,
				 const unsigned long int event_rate);


/*
 * an exponential CDF.  speeds things way up.
 */
float crckt_exp_cdf(const unsigned long int sample_rate,
		    const unsigned long int event_rate,
		    const unsigned long int nsamp);

#endif // __crckt_exp_h
