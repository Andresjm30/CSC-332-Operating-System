#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
#include <stdio.h>
#include<ctype.h>
  
int main(int argc,char *argv[]){
    
    pid_t n1,n2;
    int fd1[2], fd2[2];                                 
    char S1_str[100], S2_str[100];
    int S1_Ret,S2_Ret,S3; 
    int n,i; 
        
    if(argc<2){                             
        printf("Limit is not specified as argument\n");   
        exit(0);
    }    

    n=atoi(argv[1]);                                                                                                       
    if (pipe(fd1)==-1){                         // if pipe1 fails       
        fprintf(stderr, "Pipe1 Failed" );
        return 1;
    }
    if (pipe(fd2)==-1){                         // if pipe2 fails
        fprintf(stderr, "Pipe2 Failed" );
        return 1;
    } 
    //first child
    n1 = fork();
    if(n1<0){                                      
      fprintf(stderr, "child process1 failed");
      exit(-1);
    }
         
    // second child
    n2 = fork();
     if(n2<0){                                               
      fprintf(stderr, "child process2 failed");
      exit(-1);
    }   
  
    //parent process
    if (n1 > 0 && n2 > 0) {                   
         close(fd1[1]);                         // Close writing end of first and second pipe
         close(fd2[1]);                                                   
         wait(NULL);                           
         read(fd1[0], S1_str, 100);             // read result from child process to str
         read(fd2[0], S2_str, 100);                          
         S1_Ret=atoi(S1_str);                   // convert first result to number
         S2_Ret=atoi(S2_str);                   // convert second result to number
         S3=S1_Ret+S2_Ret;                       
         printf("S3=%d\n",S3);                  // result of parent process       
         
        
    }
    else if (n1 == 0 && n2 > 0){             // child process 1
        int S1=0;
        char S1_send[100]; 
        close(fd1[0]);                          
        for(i=1;i<=n;i=i+2){                 // calculate series (1+3+5...+n)        
        
                S1=S1+i ;
        }
        printf("S1=%d\n",S1);                   // print child process1 result
        sprintf(S1_send,"%d",S1);               
        write(fd1[1], S1_send, strlen(S1_send)+1);
        sleep(1);
    }
    else if (n1 > 0 && n2 == 0){             // child process 2
    
        int S2=0,j;

        char S2_send[100]; 
        close(fd2[0]);                            
        for(j=2;j<=n;j=j+2){                    // calculate series (2+4+6...+n)        
                S2=S2+j ;
        }
        printf("S2=%d\n",S2);                   // calculate series (1+3+5...+n)        
        sprintf(S2_send,"%d",S2);
        write(fd2[1], S2_send, strlen(S2_send)+1);
    }
    
    return 0;
}