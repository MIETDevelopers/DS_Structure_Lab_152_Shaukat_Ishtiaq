#include <stdio.h> 
int queue[5];
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
	
	if(rear == 4) {
		printf("\n!!!OVERFLOW!!!\n\n");
	}
	else if(front == -1 && rear == -1) {
		front++;
		rear++;
		printf("Enter an element: ");
		scanf("%d",queue);
	}
	else {
		rear++;
		printf("Enter an element: ");
		scanf("%d",queue+rear);
	}
}
void dequeue() {
	if(front == -1) {
		printf("\n!!!UNDERFLOW\n\n");
	}
	else if(front == rear) {
		front = rear = -1;
	}
	else {
		printf("%d has been removed.",*(queue+front));
		front++;
	}
}