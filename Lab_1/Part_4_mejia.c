#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

void repchar(char *s,char c1,char c2)
{
   int i=0;
   for(i=0;s[i];i++){
       if(s[i]==c1){
           s[i]=c2;
       }
   }
}

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
        char *c=(char *)calloc(50,sizeof(char));
        int sz=0;
		// replacing the characters 1 with L.
        while((sz=read(sfd,c,100))){
            repchar(c,'1','L');
            write(dfd,c,sz);
            write(dfd,"XYZ",3);
        }
		// closing file
        close(sfd); 
        close(dfd); 
    }
    return 0;
}