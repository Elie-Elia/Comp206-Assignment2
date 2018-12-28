#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void printArray(int height, char *array[]){
    for (int j = 0; j <= height / 2; j++){
        for(int i=1; i<height+1;i++)
            printf("%c", array[i][j]);
        printf("\n");
    }
}
void printArrayR(int height, char *array[]){
    for (int j = height/2-1; j >= 0; j--){
        for(int i=1; i<height+1;i++)
            printf("%c", array[i][j]);
        printf("\n");
    }
}
int level1(int height, int row, char* array[], int x, int y){
    int xi= x-height/2;
    int spaces,stars;
    for (spaces= (height/2)+1-row ; spaces >= 1; spaces--) {
        array[xi][y]=' ';
        xi++;
    }
    for (stars = 1; stars <= (row * 2) - 1; stars++) {
        array[xi][y]='*';
        xi++;
    }
    for (spaces = (height/2)+1-row ; spaces >=1; spaces--) {
        array[xi][y]=' ';
        xi++;
    }
}
int insertTriangle( int height, char *array[], int coord[]){
    int y=coord[1];
    int row;
    for (row = 1; row <= height/2+1; row++) {
        level1(height,row,array,coord[0],y++);
    }
}

int print_row(char* array[],int height, int level, int x, int y){
    if(level ==1) {
        int coord[]= {x,y};
        insertTriangle(height, array,coord);
    }else{
        print_row(array,height,level-1,x,y);
        print_row(array,height,level-1,x+(height/2+1)*(int)pow(2,level-2),y+(height/2+1)*(int)pow(2,level-2));
        print_row(array,height,level-1,x-(height/2+1)*(int)pow(2,level-2),y+(height/2+1)*(int)pow(2,level-2));
    }
}

int main (int argc, char *argv[]) {
    if (argc != 3) {
        printf("ERROR: Wrong number of arguments. Two required.");
        return 0;
    }
    int height = atoi(argv[1]);
    int level = atoi(argv[2]);
    if (level != 1 && (ceil(log2(height/2+1)) != floor(log2(height/2+1))|| (height/2+1 < (int)pow(2, level-1)))){
        printf("ERROR: Height does not allow evenly dividing requested number of levels\n");
        return(0);
    }

    if (height % 2 != 1 || height <= 0) {
        printf("ERROR: Bad argument. Height must be positive odd integer.");
        return 0;
    }

    char **array = (char**) malloc(sizeof(char*) * (height+1));
    for(int i=0; i<height+1;i++)
        array[i]=(char*) malloc(sizeof(char)*(height/2+1));

    int tempheight =height;
    int templevel = level;
    while(templevel-- != 1)
        tempheight = tempheight / 2;

    for (int j = 0; j <= height / 2; j++)
        for(int i=0; i<height+1;i++)
            array[i][j]=' ';
    print_row(array,tempheight,level,height/2+1,0);
    printArray(height,array);
    printArrayR(height,array);
}





