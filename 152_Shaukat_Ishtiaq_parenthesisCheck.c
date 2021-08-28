#include <stdio.h>
#include <string.h>
char stack[20];
void push(char);
void pop();
int top = -1;
int main() {
    int choice,strLen;
    char input[20];
    do {
        printf("1-Check expression.\n0-Exit\n");
        scanf("%d",&choice);
        switch(choice) {
        case 1:
            printf("\n");
            printf("Enter the expression: ");
            scanf("%s",input);
            strLen = strlen(input);
            //printf("%d",strLen);

            for(int i=0;i<strLen;i++) {
                if(input[i] == '(') {
                    push(input[i]);
                }
                else if(input[i] == ')') {
                    pop();
                }
                else {
                    continue;
                }
            }
            if(top == -1)
                printf("\n!!!Expression is properly parenthesized!!!\n\n");
            else {
                printf("\n!!!Expression is not properly parenthesized!!!\n\n");
            }
            top = -1;

        break;
        default:
            printf("\nCHOOSE THE CORRECT OPTION\n");
            break;
        }
    }while(choice!=0);
    return 0;
}

void push(char input) {
    top++;
    stack[top] = input;
}
void pop() {

        top--;
}
