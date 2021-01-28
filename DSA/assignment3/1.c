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
Node* add_after(Node * last,int data,int pos); // insertion after a particular position
Node* delete_at_beg(Node* last); // deletion at beginning of the CLL
Node* delete_at_end(Node* last); // deletion from end



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
    printf("******************************\n");
    int opt;
    Node *last = NULL;
    while(1){
        scanf("%d",&opt);
        int data,pos;
        switch(opt){
            case 1:{
                
                //insert at beginning
                printf("Enter the value\n");
                scanf("%d",&data);
                last = add_at_beg(last,data);
                printf("******************************\n");
                break;
            }
            
            case 2:{
                // insert after a particular position.
                printf("Enter the value\n");
                scanf("%d",&data);
                printf("Enter the position\n");
                scanf("%d",&pos);
                last = add_after(last,data,pos);
                printf("******************************\n");
                break;
            }
            
            case 3:{
                
                //insert at end
                printf("Enter the value\n");
                scanf("%d",&data);
                last = add_at_end(last,data);
                printf("******************************\n");
                break;
            }
            
            case 4:{
                //Delete from beginning
                last = delete_at_beg(last);
                printf("******************************\n");
                break;
            }
            
            case 5:{
                //delete before particular position
                printf("******************************\n");
                break;
            }
            
            case 6:{
                
                //delete data from end
                last = delete_at_end(last);
                printf("******************************\n");
                break;
            }
            
            case 7:{
                // display
                display(last);
                printf("******************************\n");
                break;
            }
            
            case 8:{
                
                //exit 
                exit(0);
                printf("******************************\n");
                break;
            }
            
            default :{
                printf("Invalid Option\n");
                printf("******************************\n");
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



//insertion after a particular position
Node* add_after(Node * last,int data,int pos){
    Node * p,*tmp = (Node*)malloc(sizeof(Node));
    tmp->info = data;
    p = last->link;
    int count = 0;
    do{
        if(count == pos){
            tmp->link = p->link;
            p->link = tmp;
            if(p == last){
                last = tmp;
            }
            return last;
        }
        p = p->link;
        count++;
    }while(p!=last->link);
    printf("Index out of range\n");
    return last;
}


//deletion at beginning
Node* delete_at_beg(Node* last){
    if(last == NULL){ // list is empty
        printf("List is already empty\n");
        return last;
    }
    Node* tmp = last->link;
    last->link = tmp->link;
    free(tmp);
    return last;
}


//deletion from end
Node* delete_at_end(Node* last){
    if(last == NULL){ // list is empty
        printf("List is already empty\n");
        return last;
    }
    Node* tmp;
    Node *p = last;
    while(p->link != last){  // traversing till the second last node.
        p = p->link;
    }
    tmp = last;
    p->link = last->link;
    last = p;
    free(tmp);
    return last;
}


