#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
typedef struct node * NODE;
NODE rear=NULL,front=NULL;

NODE createNode() {
	// Allocate memory for a new node
	NODE newNode = (NODE)malloc(sizeof(struct node));
	if(newNode == NULL){
		printf("Memory allocation failed\n");
		exit(0);
	}
	newNode->next = NULL;
	return newNode;
}

void insertRear(int x) {
	NODE newNode = createNode();
	newNode->data = x;

	// If the deque is empty, the new node is both front and rear
	if(front == NULL) {
		front = rear = newNode;
		return;
	}
	
	// Link the current rear to the new node and update rear
	rear->next = newNode;
	rear = newNode;
}

void insertFront(int x) {
	NODE newNode = createNode();
	newNode->data = x;
	
	// If the deque is empty, the new node is both front and rear
	if(front == NULL) {
		front = rear = newNode;
		return;
	}
	
	// New node points to the current front, then becomes the new front
	newNode->next = front;
	front = newNode;
}

void deleteFront() {
	// Check for underflow
	if(front == NULL) {
		printf("Deque is empty\n");
		return;
	}
	
	NODE temp = front;
	
	// Move front to the next node
	front = front->next;
	
	// If the list becomes empty after deletion, update rear as well
	if(front == NULL) {
		rear = NULL;
	}
	
	printf("The deleted element from Front : %d\n",temp->data);
    free(temp);
}

void deleteRear(){
	// Check for underflow
	if(front == NULL) {
		printf("Deque is empty\n");
		return;
	}

    NODE temp;
	// If there is only one element in the deque
	if(front == rear) {
		temp = front;
		front = rear = NULL;
	} else {
		// Traverse to the second to last node
		NODE second_last = front;
		while(second_last->next != rear) {
			second_last = second_last->next;
		}
		
		temp = rear;
		rear = second_last;
		rear->next = NULL;
	}
	
	printf("The deleted element from Rear : %d\n",temp->data);
    free(temp);	
}

void print()
{
    // Check if the deque is empty
    if(front == NULL) {
        printf("Deque is empty\n");
        return;
    }

	NODE temp=front;
	while(temp)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}

int main()
{
	int data,choice;
	while(1)
	{
		printf("1.Insert at Front\n2.Insert at Rear\n3.Delete from Front\n4.Delete from Rear\n5.Display\n6.Exit\n");
		printf("Enter your choice:\n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter an element to Insert at Front:");
				scanf("%d", &data);
				insertFront(data);
				break;
			case 2:
				printf("Enter an element to Insert at Rear:");
				scanf("%d", &data);
				insertRear(data);
				break;
			case 3:
				deleteFront();
				break;
			case 4:
				deleteRear();
				break;
			case 5:
				print();
				break;
			case 6:
				exit(0);
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}