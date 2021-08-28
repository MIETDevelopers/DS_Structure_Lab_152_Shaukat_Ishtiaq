#include <stdio.h>
int queue[10];
int front = -1;
int rear =-1;

void enqueue();
void dequeue();

int main() {
	int choice;
	do {
		printf("1-Enqueue\n2-Dequeue\n3-View All Elements\n0-Exit: ");
		scanf("%d",&choice);
		printf("\n");

		switch(choice) {
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				if(front == -1)
					printf("Queue is empty\n\n");
				else {
					printf("Elements in the queue are : ");
					for(int i=front;i<=rear;i++) {
						printf("%d ",*(queue+i));
					}
					printf("\n");
				}
				break;
			default:
				break;

		}

	}while(choice !=0);

	return 0;
}
void enqueue() {
    int temp;
	if(rear == 9) {
		printf("\n!!!OVERFLOW!!!\n\n");
	}
	else if(front == -1 && rear == -1) {
		front++;
		rear++;
		printf("Enter an element: ");
		scanf("%d",&queue[rear]);
	}
	else {
        int temp;

        printf("Enter an element: ");
        scanf("%d",&temp);

        int i=0,max=0,index=-1;

        for(i=0;queue[i] != '\0';i++) {
            if(temp >= queue[i] && queue[i]>=max) {
                max = queue[i];
                index = i;
            }
        }
        if(index == -1) {
            rear++;
            queue[rear] = temp;
        }
        else {
            rear++;
            for(int j=rear;j>index;j--) {
                queue[j] = queue[j-1];
            }
            queue[index] = temp;
        }
	}
}
void dequeue() {
	if(front == -1) {
		printf("\n!!!UNDERFLOW\n\n");
	}
	else if(front == rear) {
		printf("%d has been removed.\n",queue[front]);
		front = rear = -1;
	}

	else {
		printf("%d has been removed.\n",queue[front]);
		for(int i=front;i<rear;i++)
		{
			queue[i] = queue[i+1];
		}
		rear--;
	}
}
