#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
   char data;
   struct node *next;
};

struct node * creationLL(struct node * start)
{
    int n; struct node *t, *last;
    printf("How many element in LL: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        t=malloc(sizeof(struct node));
        printf("Enter Data ");
        scanf(" %c",&(t->data));
        t->next=NULL;
        if(start==NULL)
        {            start=last=t; }
        else
        { last->next=t; }
        last=t;
    }
    return start;
}

void print(struct node *start)
{
    for(;start!=NULL;start=start->next)
    printf(" %c", start->data);
}

struct node* convert(struct node *Start)
{
  int n; struct node *t=NULL,*start2=NULL,*last=NULL;
  char ch;
   for(;Start!=NULL;Start=Start->next)
    {
        t=malloc(sizeof(struct node));

       if(isalpha(Start->data)!=0)
        {
        ch=Start->data;
        }
        else
        {
            int ascii = 96+((int)(Start->data-'0')%26);
            ch = (char)ascii;
        }
        t->data=ch;
        t->next=NULL;

        if(start2==NULL)
        {
            start2=t;
        }
        else
        {
            last->next=t;
        }
        last=t;
    }
    return start2;   }


    void main(){
         struct node *Start1=NULL, *Start2=NULL;
        
         Start1=creationLL(Start1);
         printf("Before conversion: ");
         print(Start1);
         printf("\n");
         printf("After conversion: ");
         Start2=convert(Start1);
         print(Start2);
}
