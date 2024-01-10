#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/pstat.h"
#include <stddef.h>

char *convert_enum(int num) {  // function in order to convert numbers into string for enum procstate
    if(num == 0) { 
        return "UNUSED";
    }
    else if(num == 1) { 
        return "USED";
    }
    else if(num == 2) { 
        return "SLEEPING";
    }
    else if(num == 3) { 
        return "RUNNABLE";
    }
    else if(num == 4) { 
        return "RUNNING";
    }
    else if(num == 5) { 
        return "ZOMBIE";
    }
    return NULL;
}


int main() { 
    struct pstat pst;

    setpriority(15);   // set the priority of ps in to 15
    getpinfo(&pst);

    printf("  PID  PPID  PRIORITY    NAME    SIZE       STATE \n");

    for(int i = 0; i < pst.not_unused; i++) { 
        printf("   %d    %d       %d        %s      %d     %s\n",pst.pid[i],pst.ppid[i],pst.priority[i],pst.name[i],pst.size[i],convert_enum(pst.state[i]));
    }

    exit(0);
}