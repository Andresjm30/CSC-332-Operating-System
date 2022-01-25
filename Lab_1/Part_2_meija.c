#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    int fd;
    if (argc != 2){
        printf("\n Usage is executable filename\n");
        return 1;
    }

    errno = 0;
	
	// O_CREAT flag will create the file if does not exist
    fd=open(argv[1],O_RDONLY); 

    if(fd == -1){
        if(errno == ENOENT)
            printf("file does not exist\n");
        else if(errno == EACCES)
            printf("file is not accessible\n");
        return 1;
    }
    else{
        char *c=(char *)calloc(1,sizeof(char));
        int stdoutfd=1;
        while(read(fd,c,1)){
            write(stdoutfd,c,1);
        }
    }
    return 0;
}