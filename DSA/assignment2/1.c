/*Implement a menu driven Program in C for the following operations on Singly Linked List (SLL) of Student Data with the fields: Id, Name, Branch, Sem, PhNo

A. Create a SLL of N Students Data by using front insertion.

B. Display the status of SLL and count the number of nodes in it

C. Perform Insertion / Deletion at End of SLL

d. Exit*/


#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int id;
    char[] name;
    char[] branch;
    int sem;
    char[] phone_no;
    struct node next;
}Node; 

// declaration
Node* create(Node* start);
Node *insertion_at_front(Node* start,int id,char[] name,int sem,char[] phone_no,char[] branch);
void count_print(Node* start);
Node* insertion_at_end(Node* start,int id,char[] name,int sem,char[] phone_no,char[] branch);
Node *deletion(Node* start);

//Main function
int main(){
    printf("1. Create a SLL of N Students Data by using front insertion. \n2. Display the status of SLL and count the number of nodes in it \n3. Perform Insertion \n4.Deletion at End of SLL \n5. Exit");
    int opt;
    Node *start = NULL;
    scanf("%d",%opt);
    switch(opt){
        case 1:{
            
            //creation
            break;
        }
        
        case 2:{
            //print and count
            
            break;    
        }
        
        
        case 3:{
            //insertion at end
            break;
        }
        
        case 4:{
            // Deletion at end
            
            break;
        }
        
        case 5:{
            // Exit
            exit(0);
        }
        
    }
    
    return 0;
}

// display
void count_print(Node* start){
    Node* p= start;
    int count =0;
    if(p == NULL) {  // list is empty
        printf("Total Students = 0\n");        
        return;
    }
    // traversing throught the SLL
    while(p !=NULL){
        printf("Id:  %d  Name :  %s   Current Semester   Branch %s\n",p->id,p->name,p->sem,p->branch);
        p = p->next;
        count++;
    }
    printf("Total Students: %d\n",count);
    return;
}



// insertion at end
Node* insertion_at_end(Node* start,int id,char[] name,int sem,char[] phone_no,char[] branch){
    Node*tmp =(Node*)malloc(sizeof(Node));
    if(tmp == NULL){
        //memory not available
        printf("memory cannot be allocated\n");
        return start;
    }
    
    tmp->id = id;
    tmp->name= name;
    tmp->phone_no = phone_no;
    tmp->sem = sem;
    tmp->branch = branch;
    
    if(start == NULL){  // SLL is empty
        start = tmp;
        tmp->next = NULL;
        return start;
    }
    
    Node* p = start;
    while(p->next != NULL){
        p = p->next;
    }
    
    tmp->next =NULL;
    p->next = tmp;
    return start;
}


//delete at end
Node* deletion(Node* start){
    Node *tmp = start;
    if(tmp == NULL){   // list is already empty
        printf("List is already empty\n");
        return start;
    }
    if(start->next == NULL) {  // only one node is present in the SLL
        start = NULL;
        free(tmp);
        return start;
    }
    
    while(tmp->next->next != NULL){   // traversing to the second last node.
        tmp = tmp->next;
    }
    
    free(tmp->next);
    tmp->next = NULL;
    return start;
}


Node* insertion_at_front(Node*start,int id,char[] name,int sem,char[] phone_no,char[] branch){
    Node*tmp =(Node*)malloc(sizeof(Node));
    if(tmp == NULL){
        //memory not available
        printf("memory cannot be allocated\n");
        return start;
    }
    tmp->id = id;
    tmp->name= name;
    tmp->phone_no = phone_no;
    tmp->sem = sem;
    tmp->branch = branch;
    tmp->next = start;
    start = tmp;
    return start;
}


Node* creation(Node* start){
    printf("Enter the number of students\n");
    int n;
    scanf("%d",&n);
    int id,sem;
    char[] name,phone_no,branch;
    while(n!=0){
        printf("Enter Student's Name\n");
        gets(name);
        printf("Enter the Semester\n");
        scanf("%d",&sem);
        printf("Enter the student's id\n");
        scanf("%d",&id);
        printf("Enter Student's phone number\n");
        gets(phone_no);
        printf("Enter the branch (department) of the student\n");
        gets(branch);
        insertion_at_front(Node* start,id,name,sem,phone_no,branch);
        n--;
    }
    
    return start;
}


