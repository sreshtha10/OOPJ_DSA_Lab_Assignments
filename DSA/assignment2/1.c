/* I am using only dynamic memory allocation for this question and also using scanf to read strings with spaces*/


#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int id;
    char* name;
    char *branch;
    int sem;
    char *phone_no;
    struct node *next;
}Node; 

// declaration
Node *insertion_at_front(Node* start,int id,char *name,int sem,char *phone_no,char *branch);
Node* creation(Node* start);
void count_print(Node* start);
Node* insertion_at_end(Node* start,int id,char *name,int sem,char *phone_no,char *branch);
Node *deletion(Node* start);

//Main function
int main(){
    printf("Choose from the following:\n");
    printf("1. Create a SLL of N Students Data by using front insertion. \n2. Display and Count the total number of Students \n3. Insertion at end \n4. Deletion at end\n5. Exit");
    printf("\n********************\n");
    int opt;
    Node *start = NULL;
    while(1){
        scanf("%d",&opt);
        switch(opt){
            case 1:{
                
                //creation
                start = creation(start);
                printf("\n********************\n");
                break;
            }
            
            case 2:{
                //print and count
                count_print(start);
                printf("\n********************\n");
                break;    
            }
            
            
            case 3:{
                //insertion at end
                int id,sem;
                char *name,*phone_no,*branch;
                name = (char*)malloc(sizeof(char)*50);
                phone_no = (char*)malloc(sizeof(char)*11);
                branch = (char*)malloc(sizeof(char)*50);
                printf("Enter Student's Name\n");
                scanf(" %[^\n]",name);
                printf("Enter Student's Phone number\n");
                fflush(stdout);
                scanf(" %[^\n]",phone_no);
                printf("Enter Student's Branch\n");
                fflush(stdout);
                scanf(" %[^\n]",branch);
                printf("Enter the Semester ");
                scanf(" %d",&sem);
                printf("Enter the student's id ");
                scanf(" %d",&id);
                start = insertion_at_end(start,id,name,sem,phone_no,branch);
                printf("Insertion completed");
                printf("\n********************\n");
                break;
            }
            
            case 4:{
                start = deletion(start);
                // Deletion at end
                printf("Deletion completed");
                printf("\n********************\n");
                break;
            }
            
            case 5:{
                // Exit
                exit(0);
            }
            
            default: {
                printf("Invalid choice !");
                printf("\n********************\n");
            }
            
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
        printf("Id:  %d  Name :  %s   Current Semester %d   Branch %s\n",p->id,p->name,p->sem,p->branch);
        p = p->next;
        count++;
    }
    printf("Total Students: %d\n",count);
    return;
}



// insertion at end
Node* insertion_at_end(Node* start,int id,char *name,int sem,char *phone_no,char *branch){
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


Node* insertion_at_front(Node* start,int id,char *name,int sem,char *phone_no,char *branch){
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
    
    while(n!=0){
        int id,sem;
        char *name,*phone_no,*branch;
        name = (char*)malloc(sizeof(char)*50);
        phone_no = (char*)malloc(sizeof(char)*11);
        branch = (char*)malloc(sizeof(char)*50);
        printf("Enter Student's Name\n");
        scanf(" %[^\n]",name);
        printf("Enter Student's Phone number\n");
        fflush(stdout);
        scanf(" %[^\n]",phone_no);
        printf("Enter Student's Branch\n");
        fflush(stdout);
        scanf(" %[^\n]",branch);
        printf("Enter the Semester ");
        scanf(" %d",&sem);
        printf("Enter the student's id ");
        scanf(" %d",&id);
        start =  insertion_at_front(start,id,name,sem,phone_no,branch);    //using  insertion_at_front() function to create the list.
        n--;
    }
    return start;
}
