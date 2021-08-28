#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Shop{
    char name[10];
    char item[10];
    float rate;
    struct Shop *address;
};

typedef struct Shop SHOP;

SHOP *head,*tail, *newShop;

int enqueue(SHOP *, SHOP *);
int display(int,SHOP*);
int getMinimum(int,SHOP *);

char walnut[] = "walnut";
char almond[] = "almond";

int main() {
    head = NULL;
    tail = NULL;

    int choice,value;
    do{
        printf("\n1-Insert a new shop\n2-Display all rates\n3-Get minimum\n0-Exit\n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                newShop = (SHOP *) malloc(sizeof(SHOP));

                enqueue(newShop,head);
                break;
            case 2:
                printf("\n1-Walnut\n2-Almond\n");
                scanf("%d",&value);

                display(value,head);
                break;
            case 3:
                 printf("\n1-Walnut\n2-Almond\n");
                 scanf("%d",&value);

                 getMinimum(value,head);
                break;
            case 0:
                break;
            default :
                printf("\nChoose the correct option");
                break;
        }
    }while(choice!=0);

    return 0;
}

int enqueue(SHOP *newShop, SHOP *n) {
    int tester;
    float rate;

    SHOP *SL = n;

    if(head == NULL) {
        printf("\nName of the shop: ");
        scanf("%s",newShop->name);


        printf("\nSelect item--- 1-Walnut 2-Almond: ");
        scanf("%d",&tester);

        if(tester == 1)
            strcpy(newShop->item,walnut);
        else
            strcpy(newShop->item,almond);

        printf("\nRate: ");
        scanf("%f",&newShop->rate);

        newShop->address = NULL;

        head = newShop;
        tail = newShop;
    }
    else{
            printf("\nName of the shop: ");
            scanf("%s",newShop->name);


            printf("\nSelect item--- 1-Walnut 2-Almond: ");
            scanf("%d",&tester);

            if(tester == 1)
                strcpy(newShop->item,walnut);
            else
                strcpy(newShop->item,almond);

            printf("\nRate: ");
            scanf("%f",&rate);

            newShop->rate = rate;

            while(n != NULL) {
                if(rate < n->rate) {
                    if(n == head) {
                        newShop->address = head;
                        head = newShop;
                    }
                    else {
                        SL->address = newShop;
                        newShop->address = n;
                    }
                    return 0;
                }
                else if(n == tail && rate> tail->rate) {
                    tail->address = newShop;

                    newShop->address = NULL;

                    tail = newShop;
                }
                else {
                    SL = n;

                    n = n->address;
                }
            }

    }

    return 0;
}

int display(int choice, SHOP *n) {
    if(head == NULL) {
        printf("\nList is empty.\n\n\n");
    }
    else {
        while(n != NULL) {
            if(choice == 1) {
                if( !(strcmp(n->item,walnut)) ) {
                    printf("\nShop name: %s\nRate: %f\nItem: %s\n",n->name,n->rate,n->item);
                }
            }
            else if(choice == 2) {
                if(!(strcmp(n->item,almond))) {
                    printf("\nShop name: %s\nRate: %f\nItem: %s\n",n->name,n->rate,n->item);
                }
            }
            else {
                printf("\nInvalid option!!!\n\n");
                return 0;
            }
            n = n->address;
        }
    }
    return 0;
}

int getMinimum(int x,SHOP *n) {
    if(head == NULL) {
        printf("\nThe list is empty.\n\n\n");
    }
    else {
        while(n != NULL) {
            if(x == 1) {
                if( !(strcmp(n->item,walnut)) ) {
                    printf("\nShop name: %s\nRate: %f\nItem: %s\n",n->name,n->rate,n->item);
                    return 0;
                }
            }
            else if(x == 2) {
                if(!(strcmp(n->item,almond))) {
                    printf("\nShop name: %s\nRate: %f\nItem: %s\n",n->name,n->rate,n->item);
                    return 0;
                }
            }
            else {
                printf("\nInvalid option!!!\n\n");
                return 0;
            }
            n = n->address;
        }
    }
    return 0;
}
