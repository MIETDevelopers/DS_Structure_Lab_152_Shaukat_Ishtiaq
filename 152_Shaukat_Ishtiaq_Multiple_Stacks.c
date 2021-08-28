#include <stdio.h>

int stack[10];
int A = -1; //variable for controlling Stack A
int B = 10; //Variable for controlling Stack B

//Functions
void pushStackA();
void pushStackB();
void popStackA();
void popStackB();

int main() {
    int choice;
    do {
        printf("1-Push element in Stack A\n2-Push element in Stack B\n3-Pop from Stack A\n4-Pop from Stack B\n5-View elements of stack A\n6-VIew elements of Stack B\n0-Exit\n");
        scanf("%d",&choice);
        switch(choice) {
        case 1:
            pushStackA();
            break;
        case 2:
            pushStackB();
            break;
         case 3:
            popStackA();
            break;
        case 4:
            popStackB();
            break;

        case 5:
            printf("\n\n");
            printf("Elements in stack A: ");
            for(int i=0;i<=A;i++) {
                 printf("%d ",stack[i]);
            }
            printf("\n\n\n");
            break;
        case 6:
            printf("\n\n");
            printf("Elements in stack B: ");
            for(int i=9;i>=B;i--) {
                 printf("%d ",stack[i]);
            }
            printf("\n\n\n");
            break;
        }
    }while(choice !=0);

return 0;
}
void pushStackA() {
    if( (A+1) >= B) {
        printf("\n\n!!!!OVERFLOW!!!!\n\n");
    }
    else {
        A++;

        printf("Enter the element: ");
        scanf("%d",&stack[A]);
    }
}
void pushStackB() {
    if((B-1) <= A) {
        printf("\n\n!!!!OVERFLOW!!!!\n\n");
    }
    else {
        B--;

        printf("Enter the element: ");
        scanf("%d",&stack[B]);
    }
}
void popStackA() {

    if(A<0) {
        printf("\n\n!!!UNDERFLOW!!!\n\n");
    }
    else {
        stack[A] = 0;
        A--;
    }
}
void popStackB() {
    if(B>9) {
        printf("\n\n!!!!UNDERFLOW!!!\n\n");
    }
    else {
        stack[B] = 0;
        B++;

    }
}
