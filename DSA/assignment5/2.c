#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}Node;


struct node *front = NULL;
struct node *rear = NULL;

void insert(int data){
	Node* n;
	n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	if((rear==NULL)&&(front==NULL))
	{
		front = rear = n;
		rear->next = front;
	}
	else
	{
		rear->next = n;
		rear = n;
		n->next = front;
	}
} 


int delete(){ 
	Node* t;
	int x;
	t = front;
	if((front==NULL)&&(rear==NULL))
		printf("Queue Underflow\n");
	else if(front == rear){
		front = rear = NULL;
		x = t->data;
		free(t);
	}
	else{
	    x = t->data;
		front = front->next;
		rear->next = front;
		free(t);
	}
	return x;
}


void display(){ 
	Node* t;
	t = front;
	if((front==NULL)&&(rear==NULL))
		printf("Queue Underflow\n");
	else{
		do{
			printf("%d ",t->data);
			t = t->next;
		}while(t != front);
	}
	printf("\n");
	return;
}


int main(void){
    int opt,val,x;
    printf("Choose from the following\n");
    printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
    printf("*************\n");
    while(1){
        scanf("%d",&opt);
        switch(opt){
            case 1:{
                printf("Enter the value to be inserted\n");
                scanf("%d",&val);
                insert(val);
                printf("Value inserted\n");
                printf("*************\n");
                break;
            }
            
            case 2:{
                x = delete();
                printf("Deleted value = %d\n*************\n",x);
                break;
            }
            
            case 3:{
                display();
                printf("*************\n");
                break;
            }
            
            case 4:{
                exit(0);
            }
            
            default:{
                printf("Invalid option\n");
                printf("*************\n");
            }
        }
    }
    return 0;
}
