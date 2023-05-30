#ifndef SEQUENCE_TIMES_H
#define SEQUENCE_TIMES_H

const unsigned long SECONDS = 1;
const unsigned long times = SECONDS * 60 ;

//################################################### All values are stored in Minutes ##############################################################
                                                      // as per the code 1*60 = 1 minutes , where 1 sec = 0.01667 minutes
                                                      // eg - 5 sec, => 5 * 0.01667 = 0.08335 minutes
extern unsigned long sequenceTimes[25] = {
  0.08335 * times,   // On Sequence 1 (in minutes)
  15 * times,   // Off Sequence 2 (in minutes)
  
  0.08335 * times,   // On Sequence 3 (in minutes)
  15 * times,   // Off Sequence 4 (in minutes)
  
  0.08335 * times,   // On Sequence 5 (in minutes)
  150 * times,   // Off Sequence 6 (in minutes)
  
  0.08335 * times,   // On Sequence 7 (in minutes)
  120 * times,   // Off Sequence 8 (in minutes)
  
  0.08335 * times,   // On Sequence 9 (in minutes)
  120 * times,   // Off Sequence 10 (in minutes)
  
  0.08335 * times,   // On Sequence 11 (in minutes)
  60 * times,   // Off Sequence 12 (in minutes)
  
  0.08335 * times,   // On Sequence 13 (in minutes)
  60 * times,   // Off Sequence 14 (in minutes)
  
  0.08335 * times,   // On Sequence 15 (in minutes)
  60 * times,   // Off Sequence 16 (in minutes)
  
  0.08335 * times,   // On Sequence 17 (in minutes)
  60 * times,   // Off Sequence 18 (in minutes)
  
  0.08335 * times,   // On Sequence 19 (in minutes)
  60 * times,   // Off Sequence 20 (in minutes)
  
  0.08335 * times,   // On Sequence 21 (in minutes)
  90 * times,   // Off Sequence 22 (in minutes)
  
  0.08335 * times,   // On Sequence 23 (in minutes)
  90 * times   // Off Sequence 24 (in minutes)
  // // 2 * times
  


//  6 * times,   // On Sequence 1 (in minutes)
//   7 * times,   // Off Sequence 2 (in minutes)
  
//   1 * times,   // On Sequence 3 (in minutes)
//   5 * times,   // Off Sequence 4 (in minutes)
  
//    4 * times,   // On Sequence 5 (in minutes)
  // 6 * times,   // Off Sequence 6 (in minutes)
  
  // 3 * times,   // On Sequence 7 (in minutes)
  // 6 * times,   // Off Sequence 8 (in minutes)
  
  // 3 * times,   // On Sequence 9 (in minutes)
  // 5 * times,   // Off Sequence 10 (in minutes)
  
  // 5 * times,   // On Sequence 11 (in minutes)
  // 4 * times,   // Off Sequence 12 (in minutes)
  
  // 7 * times,   // On Sequence 13 (in minutes)
  // 6 * times,   // Off Sequence 14 (in minutes)
  
  // 4 * times,   // On Sequence 15 (in minutes)
  // 6 * times,   // Off Sequence 16 (in minutes)
  
  // 9 * times,   // On Sequence 17 (in minutes)
  // 6 * times,   // Off Sequence 18 (in minutes)
  
  // 5 * times,   // On Sequence 19 (in minutes)
  // 6 * times,   // Off Sequence 20 (in minutes)
  
  // 3 * times,   // On Sequence 21 (in minutes)
  // 6 * times,   // Off Sequence 22 (in minutes)
  
  // 4 * times,   // On Sequence 23 (in minutes)
  // 5 * times   // Off Sequence 24 (in minutes)










};

#endif