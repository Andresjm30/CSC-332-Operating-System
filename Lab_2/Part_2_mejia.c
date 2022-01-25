#include<sys/wait.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h> 
#include<stdlib.h>

pid_t fork();
pid_t getpid();
pid_t getppid();

int main(int argc, char const *argv[]) {

    int a=10,b=25,fq=0,fr=0;

    fq=fork(); // process Q
    if(fq==0) {
        a+=b;
        printf("\nInside child process Q \na=%d,b=%d,pid=%d",a,b,getpid());

        fr=fork(); // process R
        if(fr!=0) {
            b+=20;
            printf("\nInside parent process R \na=%d,b=%d,pid=%d",a,b,getppid());
        }
        else {
        a=(a*b)+30;
        printf("\nInside child process R \na=%d,b=%d,pid=%d",a,b,getpid());
        }
    }
    else {
        b=a+b-5;
        printf("\nInside parent process Q \na=%d,b=%d,pid=%d",a,b,getppid());
    }
    return 0;
}