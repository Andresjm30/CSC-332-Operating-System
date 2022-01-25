#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFF_SIZE 100

void replacechar(char *str, int str_len, char x, char y) {
    for (size_t i = 0; i < str_len; i ++) {
        if(str[i] == x)
            str[i] = y;
   }
}


int main()  {

    int sfd,dfd,ffd;

    sfd=open("source.txt",O_RDONLY);
    dfd=open("destination1.txt",O_WRONLY);
    ffd=open("destination2.txt",O_WRONLY);

    char size[BUFF_SIZE];
    int amount, wr;
    int dest = 1;
    int rd = 50;

    while((amount = read(sfd, size, rd))) {
        if (dest == 1) {
            replacechar(size, amount, '1', 'L');
            if (wr = (write(dfd, size, amount) == -1)) {
                fprintf(stderr, "Error writing to file destination1.txt\n");
                exit(EXIT_FAILURE);
            }

            if (amount < rd) 
                break;
        
            rd = 100;
            dest = 2;
        }
        else if (dest == 2) {
            replacechar(size, amount, '3', 'E');
            if (wr = (write(ffd, size, amount) == -1)) {
                fprintf(stderr, "Error writing to file destination2.txt\n");
                exit(EXIT_FAILURE);
            }
        
            if (amount < rd) 
                break;
        
            rd = 50;
            dest = 1;
        }

    }

    
    close(sfd); 
    close(dfd); 
    close(ffd); //closing the file

    return 0;
}