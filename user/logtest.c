#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void work() {
    volatile int calc=0;
    for (int i=0; i<100000; i++) {
        for (int j=0; j<10000; j++) {
            calc += i;
        }
    }
    exit(0);
}

int main(int argc, char *argv[]) {
    startLogging();
    int pid = fork();
    
    if (pid < 0) {
        stopLogging();
        exit(0);
    }
    if (pid == 0) {
        nice(getpid(), 10);

            // use 'logtest -...' to check for logtest priority
            // IMPORTANT: any additional arguments passed to logtest will enable this, it doesnt matter what those argument(s) are
        if (argc > 1) {
            int pid2 = fork();

            if (pid2 < 0) {
                stopLogging();
                exit(0);
            }
            if (pid2 == 0) {
                nice(getpid(), 4);
                work();
                exit(0);
            }
        }
        
        work();
        exit(0);
    }
    
    wait(0);
    stopLogging();
    exit(0);
}