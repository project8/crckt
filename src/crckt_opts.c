#include "crckt_opts.h"

int args_to_info(crckt_run_info* tgt, int argc, char** argv) {
  int result = -1;

  if(tgt) {
    int c;
    opterr = 0;
     
    while ((c = getopt (argc, argv, "e:s:f:b:t:r:")) != -1)
      switch (c)
	{
	  // event rate in Hz
	case 'e':
	  tgt->event_rate = strtol(optarg,NULL,10);
	  break;
	  // sample rate in Hz
	case 's':
	  tgt->sample_rate = strtol(optarg,NULL,10);
	  break;
	  // center frequency in Hz
	case 'f':
	  tgt->f_center    = strtol(optarg,NULL,10);
	  break;
	  // chirp bandwidth in Hz
	case 'b':
	  tgt->f_bw = strtol(optarg,NULL,10);
	  break;
	  // e- TOF in seconds
	case 't':
	  tgt->e_tof = strtol(optarg,NULL,10);
	  break;
	  // signal to noise ratio
	case 'r':
	  tgt->sn_ratio = strtol(optarg,NULL,10);
	  break;
	default:
	  /*
	   * abort parsing and return the error result
	   */
	  c = -1;
	  result = -1;
	}
  }

  return result;
}
