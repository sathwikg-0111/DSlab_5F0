<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct queue{
	struct node *front,*rear;
};
void create_queue(struct queue *q){
	q->front = q -> rear = NULL;
}
void insert(struct queue *q,int val){
	struct node *ptr = malloc(sizeof(struct node));
	ptr->data=val;
	ptr->next=NULL;
	if(q->rear==NULL){
	 q->front=q->rear = ptr;
}
	else{
	
	 q -> rear = q->rear->next = ptr;
}
}
void delete_element (struct queue *q){
	if(q->front == NULL){
		printf("\nUNDERFLOW");
		return;
	}
	struct node *temp = q ->front;
	printf("\n deleted : %d",temp->data);
	q->front = q ->front->next;
	if(q->front=NULL){
	 q->rear=NULL;
}
	free(temp);
}
int peek(struct queue *q)
{
	return (q->front) ? q->front->data : -1;
}
void display(struct queue *q){
	if(q->front==NULL){
		printf("\nQUEUE IS EMPTY");
		return;
	}
	struct node *temp=q->front;
	printf("\nQUEUE: ");
	while (temp){
		printf("%d ",temp->data);
		temp = temp ->next;
	}
}
int main(){
	struct queue q;
	int val,option;
	
	create_queue(&q);
	 do{
	 	printf("\n\n1.Insert\n2.Delete\n3.Peek\n4.Display\n5.Exit\n");
	 	printf("Enter your option");
	 	scanf("%d",&option);
	 	
	 	switch(option)
	 	{
	 		case 1:
	 			printf("Enter value: ");
	 			scanf("%d",&val);
	 			insert(&q, val);
	 			break;
	 		case 2:
	 			delete_element(&q);
	 			break;
	 		case 3:
	 			val = peek(&q);
	 			if (val != -1) printf("\nFront: %d",val);
	 			else printf("\nQUEUE IS EMPTY");
	 			break;
	 		case 4:
	 			display(&q);
	 			break;
		 }
	 } while (option != 5);
	 return 0;
}

=======
#include <stdio.h>
#include <stdlib.h>

// Define structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Global pointers for front and rear of the queue
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to add element at the rear (enqueue)
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Queue overflow!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        // Queue is empty
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d inserted into the queue.\n", value);
}

// Function to remove element from front (dequeue)
void dequeue() {
    if (front == NULL) {
        printf("Queue underflow! Nothing to dequeue.\n");
        return;
    }

    struct Node* temp = front;
    printf("Dequeued element: %d\n", temp->data);
    front = front->next;

    if (front == NULL) {
        // Queue became empty
        rear = NULL;
    }
    free(temp);
}

// Function to see the front element (peek)
void peek() {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}

// Function to display all elements
void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main menu-driven function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue using Linked List ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

>>>>>>> d18ecd26faed02bf477691d2c6b282a12aa6b3dc
