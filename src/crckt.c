#include <stdio.h>
#include "crckt_opts.h"
#include "crckt_exp.h"

// The size of the data records that mantis generates
const static int mantis_sample_size = 4194304;

int main(int argc, char** argv) {
  int result = crckt_normal;

  // Options for the run
  crckt_run_info* opts = malloc(sizeof(crckt_run_info));

  if( args_to_info(opts,argc,argv) != -1 ) {
    // Print information to terminal
    print_run_info(opts);

    // Initialize the random number generator
    mt_init();
    FILE* out = fopen("output.dat","w");

    unsigned long int sample_rate = 100;
    unsigned long int event_rate = 1000;
    unsigned long int sample_count = 0;

    while( sample_count < mantis_sample_size ) {
      sample_count += crckt_exp_draw(sample_rate,event_rate);
      fprintf(out,"%lu\n",sample_count);
    }

    fclose(out);
  }

  else {
    result = crckt_error;
  }

  return result;
}
