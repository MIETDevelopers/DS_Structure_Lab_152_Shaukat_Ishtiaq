#include <stdio.h>
#include <stdlib.h>

int main() {
    int *mal = (int*) malloc(4*sizeof(int));
    int *cal = (int*) calloc(4,sizeof(int));
    for(int i=0;i<4;i++) {
        printf("Malloc index %d = %d\n",i,mal[i]);  //malloc doesn't change the garbage value of individual memory locations.
    }
     printf("\n");
    for(int i=0;i<4;i++) {
        printf("Calloc index %d = %d\n",i,cal[i]);  //calloc changes the garbage value of individual memory locations and initializes each of them to zero.
    }
    mal = realloc(mal,5*sizeof(int));
    cal = realloc(cal,5*sizeof(int));

    free(mal);
    free(cal);
    mal = NULL;
    cal = NULL;

    return 0;
}
