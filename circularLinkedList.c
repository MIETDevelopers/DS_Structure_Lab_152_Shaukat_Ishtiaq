#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *address;
};
typedef struct Node NODE;

NODE *head,*node,*tail;

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

int display() {
    NODE *n = head;

    if(head == NULL) {
        printf("\nList is empty.\n\n");
    }
    else if(head == tail && head != NULL) {
        printf("\nElement in the list is : %d.\n\n",head->data);
    }
    else {
        printf("\nElements in the list are: ");

        while(1) {
            printf("%d ",n->data);
            n = n->address;

            if(n == head)
                break;
        }
    }
    return 0;
}

int insertion(int location) {
    node = (NODE *) malloc(sizeof(NODE));

    NODE *n = head, *SL = n;

    if(head == NULL) {
         printf("\nEnter the value you want to insert: ");
         scanf("%d",&node->data);

         node->address = NULL;

         head = node;
         tail = node;
         return 0;
    }
    else if(head == tail && head != NULL && location == 1) {
         printf("\nEnter the value you want to insert: ");
         scanf("%d",&node->data);

         node->address = head;
         head->address = node;
         tail = node;
         return 0;
    }
    else {
        for(int i = 0;i<location;i++) {
            SL = n;

            if(n == tail && i+1 == location) {
                printf("\nEnter the value you want to insert: ");
                scanf("%d",&node->data);

                node->address = head;

                n->address = node;

                tail = node;

                return 0;
            }
            else if(n == tail && i+1 < location) {
                printf("\nNode doesn't exist.\n\n");
                return 0;
            }
            else {
                n = n->address;
            }
        }
        if(n == head) {
            printf("\nEnter the value you want to insert: ");
            scanf("%d",&node->data);

            node->address = head;

            head = node;

            tail->address = head;

        }
        else {
            printf("\nEnter the value you want to insert: ");
            scanf("%d",&node->data);

            SL->address = node;
            node->address = n;
        }
    }
    return 0;
}

int deletion(int location) {
    NODE *n = head;
    NODE *SL = head;

    if(head == NULL) {
        printf("\nList is empty.\n\n");
        return 0;
    }
    else if(head == tail && head != NULL) {

        free(head);

        head = NULL;
        tail = NULL;
        return 0;
    }
    else {
        for(int i=0;i<location;i++) {
            SL = n;

            if(n == tail && location >= i) {
                printf("\nNode doesn't exist.\n\n");
                return 0;
            }
            else {
                n = n->address;
            }
        }

        if(n == tail && head->address == tail) {
            tail->address = NULL;
            head->address = NULL;

            free(tail);

            tail = head;
        }
        else if(n == tail && head->address != tail) {
            SL->address = head;

            n->address = NULL;

            free(n);

            tail = SL;

        }
        else if(n == head && head->address == tail) {
            head->address = NULL;

            free(head);

            tail->address = NULL;

            head = tail;
        }
        else if(n== head && head->address != tail) {
            n = head->address;

            head->address = NULL;

            free(head);

            head = n;

            tail->address = head;
        }
        else {
            SL->address = n->address;

            n->address = NULL;

            free(n);
        }
    }
    return 0;
}
