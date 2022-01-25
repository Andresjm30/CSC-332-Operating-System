#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fork2 = fork();
    if (fork2 < 0)
        printf("error\n");
    else if (fork2 == 0){
        printf("I'm Child 2\n");
        printf("Child 2: parent: %i\n", getppid());
        printf("I am Child 2: my pid: %i\n", getpid());

    }
    else {
        int fork1 = fork();
        if (fork1 < 0)
            printf("error\n");
        else if (fork1 == 0) {
            printf("I'm Child 1\n");
            printf("Child 1: Parent %i\n", getppid());
            printf("I am Child 1: my pid: %i\n", getpid());
        }
        else {
            printf("I'm the Parent\n");
            printf("The PIDS are:\n");
            printf("Parent: %i\n", getpid());
            printf("Child 1: %i\n", fork1);
            printf("Chuld 2: %i\n", fork2);
        }
    }
    return 0;
}