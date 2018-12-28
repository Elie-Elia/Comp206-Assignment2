#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    if(argc!=2) {
        printf("ERROR: Wrong number of arguments. One required.");
        return 0;
    }
    int height=atoi(argv[1]);
    if(height%2!=1 || height<=0){
        printf("ERROR: Bad argument. Height must be positive odd integer.");
        return 0;
    }
    int spaces, stars,row;
    for (row = 1; row < (height/2+1); row++) {
        for (spaces = (height/2)+1 - row; spaces > 0; spaces--) {
            printf(" ");
        }
        for (stars = 1; stars <= (row * 2) - 1; stars++) {
            printf("*");
        }

        printf("\n");
    }
    for (row; row>=1 ; row--) {
        for (spaces =1; spaces <=(height/2)+1-row; spaces++) {
            printf(" ");
        }
        for (stars = 1; stars <= (row * 2) - 1; stars++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
