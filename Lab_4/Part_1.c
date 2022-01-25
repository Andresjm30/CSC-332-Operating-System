#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])  {
   
    int cont = 1;
    pid_t pid;
    char *t,c;
  
    while(1)  {
        char command[1000];
        printf("> ");
      
        scanf(" %[^\n]s",command);
      
        if(!strcmp(command,"quit"))
           break;
          
        char *arg[100];
        char *token;
        char *save = NULL;
        int i = 0;
      
        for (token = strtok_r(command, " ", &save);
           token != NULL;
               token = strtok_r(NULL, " ", &save))
       {
           arg[i] = token;
           i++;
       }
        arg[i] = NULL;
      
        pid = fork();
      
        if ( pid == 0 ) {
           execvp( arg[0], arg);
           printf("file not found\n");
           return 0;
       }
      
        else {
           wait(NULL);
       }
   }
}