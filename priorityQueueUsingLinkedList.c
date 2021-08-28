#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *address;
    int data;
};
typedef struct Node NODE;
NODE *front,*rear,*node;

int enqueue(int);
int dequeue();
int display();

int main() {
    front=NULL;
    rear=NULL;

    int choice,value;

    do{
        printf("\n1-Enqueue\n2-Dequeue\n3-Display\n0-Exit ");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("\nEnter the value: ");
                scanf("%d",&value);

                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 0:
                break;
            default:
                printf("\n!!!Choose a correct option.\n\n");
                break;

        }
    }while(choice!=0);
    return 0;
}

int display() {
    NODE *n = front;

    if(front == NULL) {
        printf("\nQueue is empty.\n\n");
    }
    else {
        printf("\nElements in the queue are: ");
        while(n!=NULL) {

            printf("%d ",n->data);

            n = n->address;
        }
    }
    return 0;
}

int enqueue(int value) {
    NODE *n = front, *SL = front;

    node = (NODE *) malloc(sizeof(NODE));

    if(front == NULL) {
        node->data = value;
        node->address = NULL;

        front = node;
        rear = node;
    }
    else {
        while(n != NULL) {

            if(value > n->data) {
                node->data = value;

                node->address = n;

                if(n == front) {
                    front = node;
                    return 0;
                }
                else {
                    SL->address = node;
                    return 0;
                }
            }
            else if(n == rear && value < rear->data) {
                node->data = value;

                node->address = NULL;

                rear->address = node;

                rear = node;
            }
            else {
                SL = n;
                n = n->address;
            }
        }
    }
    return 0;
}

int dequeue() {
    NODE *temp;

    if(front == NULL) {
        printf("\n\n\t!!!!UNDERFLOW!!!!\n\n\n");
    }
    else {

        temp = (*front).address;
        printf("\n\n%d has been deleted\n\n\n",front->data);
        free(front);
        front = temp;


        if(temp == NULL)
            rear = NULL;
    }
}
