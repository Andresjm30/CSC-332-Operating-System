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
    int sfd,dfd;
    if (argc != 3){
        printf("\n Usage is executable sourcefile destinationfile\n");
        return 1;
    }

    errno = 0;

    sfd=open(argv[1],O_RDONLY);
    dfd=open(argv[2],O_WRONLY);


    if(sfd == -1){
        if(errno == ENOENT)
            printf("source file does not exist\n");
        else if(errno == EACCES)
            printf("source file is not accessible\n");
        return 1;
    }
    else{
		// copying the contents
        char *c=(char *)calloc(1,sizeof(char));
        while(read(sfd,c,1)){
            write(dfd,c,1);
        }
		//close file
        close(sfd); 
        close(dfd); 
    }
    return 0;
}