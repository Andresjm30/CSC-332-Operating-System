#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<wait.h>
#include<sys/types.h>

int main()
{
    pid_t child;

    if ((child = fork()) == 0) {
        // Child process
        // Execute Prcs_P1 to create files destination1.txt and destination2.txt
        char *args[] = {"Prcs_P1", NULL};
        if (execv(args[0], args) == -1)
        {
            fprintf(stderr, "Error executing %s.\n", args[0]);
            _exit(1);
        }

    }
    else if (child == -1) {
        fprintf(stderr, "Error creating child process\n");
        _exit(1);
    }
    else {
        // Parent process
        wait(NULL); 

        if ((child = fork()) == 0) {
            // Child process
            char *args[] = {"Prcs_P2", NULL};

            if (execv(args[0], args) == -1)   // Execute program described in step2
            {
                fprintf(stderr, "Error executing %s\n", args[0]);
                _exit(1);
            }
        }
    }
}