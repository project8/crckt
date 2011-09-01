#include <stdio.h>
#include "crckt_exp.h"

int main() {

  mt_init();

  FILE* out = fopen("output.dat","w");

  unsigned long int sample_rate = 100;
  unsigned long int event_rate = 1000;

  unsigned long int sample;
  for(int i = 0; i < 10000; i++) {
    sample = crckt_exp_draw(sample_rate,event_rate);
    fprintf(out,"%lu\n",sample);
  }

  fclose(out);
  return 0;
}
