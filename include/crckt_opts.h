#ifndef __crckt_opts_h
#define __crckt_opts_h

#include <stdlib.h>
#include <getopt.h>
#include "crckt_physics.h"

/* exiting status conditions */
const static int crckt_normal = 0;
const static int crckt_error  = 1;

/* bitmask constants for configuration */

#define chk_bit(someinfo,somebit) ((someinfo->conf_mask & somebit) == somebit)
const static int event_rate_set = 0x1;
const static int sample_rate_set = 0x2;
const static int f_center_set = 0x4;
const static int f_bw_set = 0x6;
const static int sn_ratio_set = 0x8;
const static int e_tof_set = 0x10;

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
  unsigned char conf_mask;    // Configuration info about user settings
} crckt_run_info;

/*
 * parse the input arguments into a crckt_run_info struct.  this
 * calls getopt and does some magical things.
 */
int args_to_info(crckt_run_info* tgt, int argc, char** argv);


/*
 * takes care of default parameters
 */
void process_defaults(crckt_run_info* info);

#endif // __crckt_opts_h
