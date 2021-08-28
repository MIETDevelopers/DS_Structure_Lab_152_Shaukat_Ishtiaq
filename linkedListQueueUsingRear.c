#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *address;
};
typedef struct Node NODE;

int enqueue(NODE *, int,NODE *);
int dequeue(NODE *);
int display(NODE *);

NODE *head,*node, *rear;

int main() {
    head = (NODE *) malloc(sizeof(NODE));
    head->address = NULL;

    int choice,value;

    do{
        printf("\n1-Enqueue\n2-Dequeue\n3-Display\n0-Exit: ");
        scanf("%d",&choice);

        switch(choice) {

            case 1:
                node = (NODE *) malloc(sizeof(NODE));

                printf("\nEnter the value: ");
                scanf("%d",&value);

                enqueue(head,value,rear);
                break;
            case 2:
                dequeue(head);
                break;
            case 3:
                display(head);
                break;
             case 0:
                printf("\n----SAYONARA----\n");
                break;
            default:
                printf("\n\nEnter the correct option\n\n");
                break;
        }
    }while(choice!=0);

    return 0;
}

int enqueue(NODE *head,int value, NODE *x) {

    NODE *n;

    if(head->address == NULL) {

        node->address = head->address;

        head->address = node;

        node->data = value;

        rear = node;
    }
    else {
        node->data = value;

        node->address = x->address;

        x->address = node;

        rear = node;
    }

    return 0;
}

int dequeue(NODE *head) {
    NODE *n;

    if(head->address == NULL)
        printf("\n\n----UNDERFLOW-----\n\n");
    else {

        n = head->address;

        head->address = n->address;

        n->address = NULL;

        printf("\n%d has been dequeued.\n\n",n->data);

        free(n);
    }
    return 0;
}

int display(NODE *head) {

    NODE *n;

    if(head->address == NULL) {
        printf("\n\nQueue is empty.\n\n");
    }
    else {
        n = head->address;

        printf("\nElements in the queue are: ");

        while(n != NULL) {
            printf("%d ",n->data);
            n = n->address;
        }
    }
    return 0;
}
