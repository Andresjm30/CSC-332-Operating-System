#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> 

int main() {
    int pid = fork();
    if (pid == 0) {
        printf("Parent process id: %d\n", getppid());
        printf("Child process successfully spawned the process id: %d\n", getpid());
        execl("/bin/date", "date", NULL);
    }
    else {
        wait(NULL);
    }

    return 0;
}