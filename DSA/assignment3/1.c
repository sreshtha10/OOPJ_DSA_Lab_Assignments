#include<stdlib.h>
#include<stdio.h>

typedef struct node{
    int info;
    struct node* link;
}Node;



//function declarations.
void display(Node *last);  // display method.
Node* add_at_end(Node* last,int data); // insertion at end.
Node* add_at_beg(Node* last,int data); // insertion at beginning



//Main function
int main(){
    printf("Choose from the following\n");
    printf("1. Insert data at beginning\n");
    printf("2. Insert data at after particular position\n");
    printf("3. Insert data at end of LL\n");
    printf("4. Delete data from beginning\n");
    printf("5. Delete data before Particular position \n");
    printf("6. Delete data from End\n");
    printf("7. Display the Current status\n");
    printf("8. Exit\n");
    printf("******************************");
    int opt;
    Node *last = NULL;
    while(1){
        scanf("%d",&opt);
        switch(opt){
            case 1:{
                
                //insert at beginning
                printf("******************************");
                break;
            }
            
            case 2:{
                
                // insert after a particular position.
                printf("******************************");
                break;
            }
            
            case 3:{
                
                //insert at end
                printf("******************************");
                break;
            }
            
            case 4:{
                
                //Delete from beginning
                printf("******************************");
                break;
            }
            
            case 5:{
                //delete before particular position
                printf("******************************");
                break;
            }
            
            case 6:{
                
                //delete data from end
                printf("******************************");
                break;
            }
            
            case 7:{
                // display
                display(last);
                printf("******************************");
                break;
            }
            
            case 8:{
                
                //exit 
                exit(0);
                printf("******************************");
                break;
            }
            
            default :{
                printf("Invalid Option\n");
                printf("******************************");
            }
        }
    }
}//end of Main function





//display method
void display(Node *last){
    if(last == NULL){
        printf("List is empty");
        return;
    }
    Node *p;
    p = last->link;
    do{
        printf("%d ",p->info);
        p = p->link;
    }while(p!= last->link);
    printf("\n");
    return;
}




//insertion at end
Node* add_at_end(Node* last,int data){
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->info = data;
    if(last == NULL){ // list is empty
        last = tmp;
        tmp->link = last;
        return last;
    }
    tmp->link = last->link;
    last->link = tmp;
    last = tmp;
    return last;
}


//insertion at beginning
Node* add_at_beg(Node* last,int data){
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->info = data;
    if(last == NULL) {// empty list
        last = tmp;
        tmp->link = last;
        return last;
    }
    tmp->link = last->link;
    last->link = tmp;
    return last;
}




