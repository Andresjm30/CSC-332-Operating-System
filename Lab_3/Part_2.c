#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    char* cmd = "ls";
    char* args[] = {"ls", "-al", NULL};
    pid_t pid;
    int st;
    if ((pid = fork()) < 0) {
        printf("Fork Failed");
        exit(1);
    }
    else if (pid == 0) {
        printf("Successful forked child process, child process pid = %u", pid);
        st = execvp(cmd, args);
        if (st == 1) {
            printf("EXECVP failed\n");
            return 1;
        }
    }
    else {
        printf("Fork successful, Child process pid: %d\n", pid);
    }

    return 0;
}