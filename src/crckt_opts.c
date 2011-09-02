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
	  tgt->conf_mask |= event_rate_set;
	  break;
	  // sample rate in Hz
	case 's':
	  tgt->sample_rate = strtol(optarg,NULL,10);
	  tgt->conf_mask |= sample_rate_set;
	  break;
	  // center frequency in Hz
	case 'f':
	  tgt->f_center    = strtol(optarg,NULL,10);
	  tgt->conf_mask |= f_center_set;
	  break;
	  // chirp bandwidth in Hz
	case 'b':
	  tgt->f_bw = strtol(optarg,NULL,10);
	  tgt->conf_mask |= f_bw_set;
	  break;
	  // e- TOF in seconds
	case 't':
	  tgt->e_tof = strtol(optarg,NULL,10);
	  tgt->conf_mask |= e_tof_set;
	  break;
	  // signal to noise ratio
	case 'r':
	  tgt->sn_ratio = strtol(optarg,NULL,10);
	  tgt->conf_mask |= sn_ratio_set;
	  break;
	default:
	  /*
	   * abort parsing and return the error result
	   */
	  c = -1;
	  result = -1;
	}

    process_defaults(tgt);
  }

  return result;
}

void process_defaults(crckt_run_info* info) {
  if( !chk_bit(info,event_rate_set) ) {
    info->event_rate = 1; // Default event rate is 1 Hz
  }

  if( !chk_bit(info,sample_rate_set) ) {
    info->sample_rate = 5e8; // Default event rate is 500 MHz
  }

  if( !chk_bit(info,f_center_set) ) {
    info->f_center = 5e7; // Default event rate is 50MHz
  }

  if( !chk_bit(info,f_bw_set) ) {
    info->f_bw = 5e7; // Default event rate is 50MHz
  }

  if( !chk_bit(info,e_tof_set) ) {
    info->e_tof = 1; // Default time of flight is 30us in samples
  }

  if( !chk_bit(info,sn_ratio_set) ) {
    info->sn_ratio = 2; // Default signal to noise is 2
  }
}
