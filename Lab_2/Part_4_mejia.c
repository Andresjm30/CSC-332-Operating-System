#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[]){

    int fd[2]; 
    char buffer[100];

    //opening the pipe for use and testing to see if it fails
    if (pipe(fd) == -1) {
        printf("The call to pipe has failed.");
        return 1;
    }

    int frk = fork();
    if (frk == 0) {
        //child created
        close(fd[0]);  
        int fileFd = open(argv[1], O_RDONLY); 
        
        int n = read(fileFd, buffer, sizeof(buffer));
        close(fileFd);

        // writing the data found in the buffer to the pipe
        write(fd[1], buffer, n);
        close(fd[1]);
        exit(0); 
    }

    else if (frk > 0) // were in the parent process
    {
        close(fd[1]); 
        
        // Wait for child to send a string
        wait(NULL);

        int fileFd = open(argv[1], O_WRONLY);
        
        int n = sprintf(buffer, "Parent is writing: ");
        write(fileFd, buffer, n); //writing the message to the file

        // reading what was written to the pipe from the child
        int reading = read(fd[0], buffer, sizeof(buffer));
        buffer[reading] = 0;

        write(fileFd, buffer, reading);
        close(fileFd);
        close(fd[0]);
    }


    return 0;
    
}