#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *address;
};
typedef struct Node NODE;

int push(NODE *,NODE *, int);
int pop(NODE *);
int display(NODE *);
int peek();

NODE *head,*node;

int main() {
    head = (NODE *) malloc(sizeof(NODE));
    head->address = NULL;

    int choice,value;
    do {
        printf("\n1-Push\n2-Pop\n3-Display\n0-Exit: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                node = (NODE *) malloc(sizeof(NODE));   //Creating a new node.

                printf("\nEnter the value: ");
                scanf("%d",&value);

                push(head,node,value);
                break;
            case 2:
                pop(head);
                break;
            case 3:
                display(head);
                break;
            case 0:
                printf("\n\nGoodbye!\n\n");
                break;
            default:
                printf("\n\n!!!Choose the correct option!!!\n\n");
                break;

        }
    }while(choice!=0);
}

int push(NODE *head,NODE *node, int value) {

        node->address = head->address;
        head->address = node;
        node->data = value;

    return 0;
}

int pop(NODE *head) {
    NODE *n;
    int returnValue;

    if(head->address == NULL) {
        printf("\n-----UNDERFLOW-----\n");
    }
    else {
        n = head->address;

        head->address = n->address;

        n->address = NULL;

        returnValue = n->data;

        free(n);

        printf("\n\n%d has been popped out.\n\n",returnValue);
    }
    return 0;
}

int display(NODE *head) {
    NODE *n;

    if(head->address == NULL) {
        printf("\n\n-----Stack is empty-----\n\n");
    }
    else {
        n = head->address;
        printf("\n\nElements in the stack are: ");

        while( n!= NULL) {
            printf("%d ",n->data);
            n = n->address;
        }
    }
    return 0;
}
