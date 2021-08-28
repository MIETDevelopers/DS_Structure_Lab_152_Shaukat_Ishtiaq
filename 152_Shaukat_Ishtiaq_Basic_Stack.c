#include <stdio.h>
void push(int[]);
void pop(int[]);
int counter;
int main() {
    int stack[5],choice;
        printf("Enter 3 values\n");
    for(int i=0;i<3;i++) {
        counter++;
        printf("Enter value no %d: ",i+1);
        scanf("%d",&stack[i]);
    }
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
    if(counter ==5) {
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
        //int x = counter-1;
        stack[counter-1]=0;
        counter--;
    }
}
