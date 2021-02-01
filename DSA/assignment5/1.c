// Linked list implementation of queue
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}Node;

Node *front = NULL;
Node *rear = NULL;

void insert(int x){
    Node* tmp = (Node*)malloc(sizeof(Node));
    if(tmp == NULL){
        printf("Queue Overflow\n");
        return;
    }
    tmp->data = x;
    if(front == NULL){
        front = tmp;
    }
    else{
        rear->next = tmp;
    }
    rear = tmp;
    tmp->next = NULL;
    return;
}


int delete(){
    if(front == NULL){
        printf("Queue Underflow\n");
        return -1;   // -1 will be returned if Underflow occurs
    }
    int x = front->data;
    Node * tmp = front;
    front  = front->next;
    free(tmp);
    return x;
}


int peek(){
    if(front == NULL){
        printf("Queue Underflow\n");
        exit(1);
    }
    return front->data;
}



void display(){
    Node* p = front;
    if(front == NULL){
        printf("Queue Underflow\n");
        return;
    }
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
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
}
