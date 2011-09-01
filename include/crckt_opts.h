#ifndef __crckt_opts_h
#define __crckt_opts_h

#include <stdlib.h>
#include <getopt.h>

/* exiting status conditions */
const static int crckt_normal = 0;
const static int crckt_error  = 1;

/*
 * i like structs.  they help keep things clean.  this one contains 
 * all of the information regarding a particular cricket run.
 */
typedef struct {
  unsigned long int event_rate; // This is in hertz
  unsigned long int sample_rate; // This is in hertz
  unsigned long int f_center; // Chirp center frequency, Hz
  unsigned long int f_bw;     // Chirp bandwidth, Hz
  unsigned long int e_tof;    // time of flight in seconds
  unsigned int sn_ratio;      // A constant
} crckt_run_info;

/*
 * parse the input arguments into a crckt_run_info struct.  this
 * calls getopt and does some magical things.
 */
int args_to_info(crckt_run_info* tgt, int argc, char** argv);

#endif // __crckt_opts_h
