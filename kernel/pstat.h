#include "param.h"

struct pstat { 
  int pid[NPROC];
  int priority[NPROC];
  char name[NPROC][16];
  int ppid[NPROC];
  int size[NPROC];
  enum procstate state[NPROC];
  int not_unused;   // number of not UNUSED
};  
