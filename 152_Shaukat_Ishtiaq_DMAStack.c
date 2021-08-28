#include <stdio.h>
#include <stdlib.h>

void push(int[]);
void pop(int[]);

int counter;
int numberOfElements;

int main() {
    int choice;
    printf("Size of stack? ");
    scanf("%d",&numberOfElements);

    int *stack = (int*) malloc(numberOfElements * sizeof(int));

    do{
    printf("1-Push\n2-Pop\n3-View\n0-Exit\n");
    scanf("%d",&choice);
    printf("\n");

    switch(choice) {
    case 1:
        push(stack);
        break;
    case 2:
        pop(stack);
        break;
    case 3:
        printf("Elements in the stack are:\n");
        for(int i=0;i<counter;i++) {
            printf("%d\n",stack[i]);
        }
        printf("\n");
        break;
    }
}while(choice!=0);
    return 0;
}

void push(int stack[]) {
    if(counter ==numberOfElements) {
        printf("!!!!OVERFLOW!!!!\n");
    }
    else {
        printf("Enter the value you want to add: ");
        scanf("%d",&stack[counter]);
        counter++;
    }
}
void pop(int stack[]) {
    if(counter == 0) {
        printf("!!!!UNDERFLOW!!!!\n");
    }
    else {
        counter--;
    }
}
