#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *address;
 };
struct Node *head,*temp,*node;

//functions
void insertEnd(struct Node*,struct Node*,struct Node*);
void display(struct Node *);
void search(struct Node *,int);
void deleteEnd(struct Node *);
int insertSpecific(struct Node*,struct Node*,struct Node*, int);
int deleteSpecific(struct Node*, int);


int main() {
    head = (struct Node *) malloc(sizeof(struct Node));
    temp = (struct Node *) malloc(sizeof(struct Node));
    head->address = NULL;

    int choice ,searchElement, insertionPosition;

    do{
        printf("\n1-InsertEnd\n2-InsertSpecificPosition\n3-Display\n4-Search\n5-DeleteEnd\n6-DeleteSpecific\n0-Exit: ");
        scanf("%d",&choice);
        node = (struct Node *) malloc(sizeof(struct Node));

        switch(choice) {
            case 1:
                insertEnd(head,node,temp);
                break;
            case 2:
                printf("Enter the node number: ");
                scanf("%d",&insertionPosition);

                insertSpecific(head,node,temp,insertionPosition);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("\nEnter the element you want to search: ");
                scanf("%d",&searchElement);
                search(head,searchElement);
                break;
            case 5:
                deleteEnd(head);
                break;
             case 6:
                printf("Enter the node number: ");
                scanf("%d",&insertionPosition);

                deleteSpecific(head,insertionPosition);
                break;
            case 0:
                break;
            default:
                printf("\nDefault case has been called.\n");
                break;

        }
    }while(choice!=0);
    return 0;
}

void insertEnd(struct Node *head,struct Node *node,struct Node *temp) {
    if(head->address == NULL) {
        head->address = node;

        printf("\nEnter a value to be inserted: ");
        scanf("%d",&node->data);

        node->address = NULL;

        temp->address = node;   //Saving the address of the new node for later use.
    }
    else {
        temp->address->address = node;

        printf("\nEnter a value to be inserted: ");
        scanf("%d",&node->data);

        node->address = NULL;

        temp->address = node;
    }
}

void display(struct Node *head) {

    struct Node *n;
    n = head->address;
    if(n == NULL) {
        printf("\n\nThe linked list is empty\n\n");
    }
    else {

        printf("\n\nData elements in the linked list are: ");

        while(n != NULL) {
            printf("%d ",n->data);
            n = n->address;
        }
        printf("\n\n\n");
    }
}

void search(struct Node *head,int x) {
    struct Node *n;
    n = head->address;

    int i = 0;
    while(n!= NULL) {
        i++;
        if(n->data == x) {
            printf("\nValue found: Node no: %d\n",i);
        }
        n = n->address;
    }
}

void deleteEnd(struct Node *head) {
    struct Node *n;
    struct Node *secondLast;

    if(head->address == NULL) {
        printf("\nNo element left to delete\n");
    }
    else {
        n = head;
        while(n->address!= NULL) {
            secondLast = n;
            n = n->address;
        }
        secondLast->address = NULL;

    }
}

int insertSpecific(struct Node *head,struct Node *node,struct Node *temp, int position) {
    struct Node *n = head;

    for(int i=0;i<position;i++) {
        if(n->address == NULL && i+1 == position) {
            break;
        }
        else if(n->address == NULL) {
            printf("\nSpecific node doesn't exist\n.");
            return 0;
        }
        else {
            n = n->address;
        }
    }

    printf("\n\nEnter the value you want to insert: ");
    scanf("%d",&node->data);

    node->address = n->address;
    n->address = node;

    temp->address = node;

    return 0;
}

int deleteSpecific(struct Node* head, int position) {
    struct Node *ptr,*secondLast, *n;

    n = head;

    for(int i =0;i<position;i++) {
        secondLast = n;

        if(head->address == NULL) {
            printf("\nThe list is empty\n\n");
            return 0;
        }
        else if(n->address == NULL) {
            printf("\n\nThe node doesn't exist.\n\n");
            return 0;
        }
        else {
            n = n->address;
        }
    }

    ptr = n;
    secondLast->address = n->address;
    free(ptr);

    return 0;

}
