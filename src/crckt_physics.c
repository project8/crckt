#include "crckt_physics.h"

unsigned long int discretize(unsigned long int sample_rate, 
			     float time_interval) {
  float interval = delta_ticks(sample_rate);
  return (unsigned long)(floor(time_interval/interval));
}

float delta_ticks(unsigned long int sample_rate) {
  return 1.0/(float)sample_rate;
}
