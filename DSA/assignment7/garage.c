#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h> 

struct node { 
int car_id, sr_time; 
struct node*next; 
}; 

struct node *head=NULL; 

void enter_garage(int a, int b)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->car_id = a;
    newnode->sr_time = b;
    newnode->next = NULL;
    if(head==NULL)
    {
        head = newnode;
    }
    if(b>(head->sr_time))
    {
        struct node *temp;
        temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    else if(b<(head->sr_time))
    {
        newnode->next=head;
        head=newnode;
    }
}

int exit_garage()
{
    if(head == NULL)
    {
        printf("Empty garage");
        return 0;
    }
    else
    {
        struct node *temp;
        temp = head;
        head = head->next;
        return(temp->car_id);
    }
}

void main() 
{ 
int choice, car_id, time,x; 
do 
{ 
printf("Enter your choice\n");
printf("1.Car Entry in Garage for Service\n2. Car Exit from Garage –Service Completed\n 3. Exit\n"); 
scanf("%d", &choice); 
switch(choice) 
{ 
case 1: printf("enter car_id and service time");
    scanf("%d%d", &car_id, &time); 
    enter_garage(car_id,time); 
    break; 
case 2: 
    x=exit_garage(); 
    printf("The removed car id is %d ", x); 
    break; 
case 3: 
    exit(0); 
} 
} while(choice>=1 && choice<=3); 
getch(); 
}
