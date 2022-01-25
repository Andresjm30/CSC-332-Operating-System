#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> //Need for close

int main() {
    if (creat("destination1.txt",0777) == -1) {
        fprintf(stderr, "Error creating file destination1.txt\n");
        return 1;
    }

    if (creat("destination2.txt",0777) == -1) {
        fprintf(stderr, "Error creating file destination2.txt\n");
        return 1;
    }

    return 0;
}