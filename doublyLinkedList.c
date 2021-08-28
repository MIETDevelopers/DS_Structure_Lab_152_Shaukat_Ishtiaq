#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *pre;
    struct Node *next;
    int data;
};
typedef struct Node NODE;

NODE *head,*tail,*node;

int insertion(int);
int deletion(int);
int display();

int main() {
    head = NULL;
    tail = NULL;

    int choice,location;

    do{
         printf("\n1-Insert\n2-Display\n3-Delete\n0-Exit: ");
         scanf("%d",&choice);

         switch(choice) {

            case 1:
                printf("\nEnter the location where you want to insert: ");
                scanf("%d",&location);

                insertion(location);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("\nEnter the node number you want to delete: ");
                scanf("%d",&location);

                deletion(location);
                break;
            default:
                printf("\n\nEnter the correct option\n\n");
                break;
        }
    }while(choice!=0);
    return 0;
}

int insertion(int location) {
    node = (NODE *) malloc(sizeof(NODE));
    NODE *n = head;


    if(head == NULL) {

        printf("\nEnter the value: ");
        scanf("%d",&node->data);

        node->pre = NULL;
        node->next = NULL;

        head = node;
        tail = node;
    }

    else {

        for(int i=0;i<location;i++) {

            if(n == NULL) {
                printf("\nNode doesn't exist.\n");

                return 0;
            }
            else if(n->next == NULL && i+1 == location) {

                 printf("\nEnter the value: ");
                 scanf("%d",&node->data);

                 node->pre = n;
                 node->next = NULL;
                 n->next = node;

                 tail = node;

                return 0;
            }
            else {
                n = n->next;
            }
        }

        printf("\nEnter the value: ");
        scanf("%d",&node->data);

        node->pre = n->pre;
        node->next = n;
        n->pre = node;

        if(n == head) {
            head = node;
        }
        else {
            node->pre->next = node;
        }
    }
}

int display() {
    NODE *n = head;

    if(head == NULL) {
        printf("\nList is empty\n\n");
    }
    else {

        printf("\nElements in the linked list are: ");

        while(n!=NULL) {
            printf("%d ",n->data);
            n = n->next;
        }
    }
    return 0;
}

int deletion(int location) {
    NODE *n = head;
    NODE *ptr;

    if(head == NULL) {

        printf("\nList is empty.\n\n");
    }
    else if(head == tail) {
        free(head);

        head = NULL;
        tail = NULL;
    }
    else {

        for(int i=0;i<location;i++) {
            if(n->next == NULL) {
                printf("\nNode doesn't exist.\n\n");
            }
            else {
                n = n->next;
            }
        }

        if(n == head) {
            ptr = head->next;
            head->next->pre = NULL;
            free(head);
            head = ptr;
        }
        else if(n == tail) {
            ptr = n->pre;
            ptr->next = NULL;
            free(tail);
            tail = ptr;
        }
        else {
            n->pre->next = n->next;
            n->next->pre = n->pre;
            free(n);
        }
    }
    return 0;
}
