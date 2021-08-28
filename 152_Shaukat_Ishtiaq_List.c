#include <stdio.h>
#include <stdlib.h>
void insertAtEnd(int [],int);
void insertMiddle(int [],int);
void deleteElement(int []);
void searchElement(int []);

static int index = 0;
int main() {
    int number;
    printf("How many values do you want to insert: ");
    scanf("%d",&number);
    int *array = (int*) malloc(sizeof(int)*number);
    int choice;
    printf("Enter %d values\n",number);
    for(int i=0;i<number;i++) {
        printf("Enter element number %d: ",i+1);
        scanf("%d",&array[i]);
        index++;
    }

    do {
        printf("\n 1-Insert at the end\n 2- Insert in the middle\n 3- View Elements\n 4-Delete an element\n 5-Search Element\n 0-Exit\n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                //insert an element in the end.
                insertAtEnd(array,number);
            break;
            case 2:
                //insert an element in the end.
                insertMiddle(array,number);
            break;
            case 3:
                //print array on screen.
                for(int i=0;i<index;i++) {
                    printf("\nElement number %d: %d",i+1,array[i]);
                }
            break;
            case 4:
                //delete an element.
                deleteElement(array);
            break;
            case 5:
                //search element.
                searchElement(array);
            break;

            default:
                printf("\nChoose a valid option");
            break;
        }
    }while(choice!=0);

    return 0;
}
void insertAtEnd(int arr[],int number) {
    int x,num;

    printf("\nHow many values do you want to insert: ");
    scanf("%d",&num);
    int sizeOfArray = number+num;
    arr = realloc(arr,sizeOfArray*sizeof(int));
    for(int i=0;i<num;i++) {
    printf("Enter the value to be inserted: ");
    scanf("%d",&x);
    arr[index] = x;
    index++;
    }

}
void deleteElement(int arr[]) {
    int checker = 0;
    int value;
    printf("\nEnter the number to be deleted: ");
    scanf("%d",&value);

    for(int i=0;i<=index;i++) {
        if(arr[i]==value) {
            checker = 1;
        }
        if(i == index)
            index -= 1;
        if(checker == 1) {
            arr[i] = arr[i+1];
        }
    }
}
void searchElement(int arr[]) {
    int value;

    printf("\nEnter the number to be searched: ");
    scanf("%d",&value);

    for(int i=0;i<=index;i++) {
        if(arr[i] == value) {
            printf("\nElement found \n Index of found element = %d",i);
        }
    }
}
void insertMiddle(int arr[],int number) {
    int x,location;
    number += 1;
    arr = realloc(arr,number*sizeof(int));

    printf("\nEnter the desired index: ");
    scanf("%d",&location);

    for(int i=index;i>location;i--) {
        arr[i] = arr[i-1];
    }

    printf("Enter the value to be inserted: ");
    scanf("%d",&x);

    arr[location] = x;
    index++;
}

