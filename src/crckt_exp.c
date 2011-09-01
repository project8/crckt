#include "crckt_exp.h"

// DEBUG
#include <stdio.h>

unsigned long int crckt_exp_draw(const unsigned long int sample_rate,
				 const unsigned long int event_rate) {
  unsigned long int r = mt_random();
  float prob = (float)r/4294967295.0; // random divided by 2^32 - 1

  unsigned long int samp = 0;
  float val = 0.0;
  while( prob > val ) {
    val = crckt_exp_cdf(sample_rate,event_rate,samp);
    samp++;
  }
  return samp;
}

float crckt_exp_cdf(const unsigned long int sample_rate,
		    const unsigned long int event_rate,
		    const unsigned long int nsamp) {
  float exp_arg = (float)(sample_rate*nsamp)/(float)event_rate;
  return 1.0 - exp(-exp_arg);
}
