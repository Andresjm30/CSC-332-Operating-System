#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>


int main(int argc, char* argv[])
{
    int fd;
    if (argc != 2){
        printf("\n Usage :\n");
        return 1;
    }

    errno = 0;

    // O_CREAT flag will create the file if does not exist
    fd=open(argv[1],O_CREAT | O_RDONLY);

    if(fd == -1){
        printf("\n open() failed with error [%s]\n",strerror(errno));
        return 1;
    }
    else{
        printf("\n open() successful\n");
    }
    return 0;
}