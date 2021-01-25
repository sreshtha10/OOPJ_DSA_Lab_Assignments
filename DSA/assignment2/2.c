/* I have used dynamic memory allocation in this question also and used scanf for input for strings*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int id;
    char *name;
    char *dept;
    char *designation;
    char *phn;
    long long int salary;  //employee sal may be very high, that's why I'm using long long int.
    struct node* next;
    struct node* prev;
}Empl;


//function declaration
Empl *insertion_at_front(Empl* start,int id,char *name,char* dept,char* designation, long long int salary,char *phn);
Empl  *creation(Empl* start);
void count_print(Empl* start);
Empl* insertion_at_end(Empl* start,int id,char *name,char* dept,char* designation, long long int salary,char *phn);
Empl *deletion(Empl* start);




//Main function
int main(){
    printf("Choose from the following:\n");
    printf("1. Create a DLL of N Employees Data by using end insertion \n2. Display and Count the total number of Employees \n3. Insertion at end \n4. Deletion at end\n5. Exit");
    printf("\n********************\n");
    int opt;
    Empl *start = NULL;
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
                int id;
                long long int salary;
                char *name,*dept,*designation,*phn;
                name = (char*)malloc(sizeof(char)*50);
                designation = (char*)malloc(sizeof(char)*50);
                dept = (char*)malloc(sizeof(char)*50);
                phn = (char*)malloc(sizeof(char)*11);
                printf("Enter Employee's Name\n");
                scanf(" %[^\n]",name);
                printf("Enter Employee's designation\n");
                fflush(stdout);
                scanf(" %[^\n]",designation);
                printf("Enter Employee's department\n");
                fflush(stdout);
                scanf(" %[^\n]",dept);
                printf("Enter Employee's Contact Number\n");
                fflush(stdout);
                scanf(" %[^\n]",phn);
                printf("Enter the Employee's salary ");
                scanf(" %lld",&salary);
                printf("Enter the Employee's id ");
                scanf(" %d",&id);
                start = insertion_at_end(start,id,name,dept,designation,salary,phn);
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
//end of Main 


// display and counting total Employees
void count_print(Empl* start){
    Empl* p= start;
    int count =0;
    if(p == NULL) {  // list is empty
        printf("Total Employees = 0\n");        
        return;
    }
    // traversing throught the DLL
    while(p !=NULL){
        printf("Id:  %d  Name :  %s   Department  %s   Designation %s  Salary %lld Contact Number %s\n",p->id,p->name,p->dept,p->designation,p->salary,p->phn);
        p = p->next;
        count++;
    }
    printf("Total Employees: %d\n",count);
    return;
}




//insertion at front of DLL

Empl* insertion_at_front(Empl* start,int id,char *name,char* dept,char* designation, long long int salary,char* phn){
    Empl*tmp =(Empl*)malloc(sizeof(Empl));
    if(tmp == NULL){
        //memory not available
        printf("memory cannot be allocated\n");
        return start;
    }
    tmp->id = id;
    tmp->name= name;
    tmp->dept =dept;
    tmp->designation = designation;
    tmp->salary = salary;
    tmp->phn = phn;
    
    if(start == NULL) { // DLL is empty
        start = tmp;
        tmp->next = NULL;
        tmp->prev = NULL;
        return start;
    }
    
    tmp->next = start;
    tmp->prev = NULL;
    start->prev = tmp;
    start = tmp;
    return start;
}


//insertion at end of DLL
Empl* insertion_at_end(Empl* start,int id,char *name,char* dept,char* designation, long long int salary,char* phn){
    Empl* tmp,*p;
    tmp =(Empl*)malloc(sizeof(Empl));
    if(tmp == NULL){
        //memory not available
        printf("memory cannot be allocated\n");
        return start;
    }
    
    tmp->id = id;
    tmp->name= name;
    tmp->dept =dept;
    tmp->designation = designation;
    tmp->salary = salary;
    tmp->phn = phn;
    
    p = start;
    while(p->next != NULL){
        p = p->next;
    }
    tmp->next = p->next;
    tmp->prev = p;
    p->next = tmp;
    return start;
}



// Deletion at end of DLL
Empl *deletion(Empl* start){
    Empl *tmp = start;
    if(tmp == NULL){   // DLL is already empty
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


// creation function
Empl* creation(Empl* start){
    printf("Enter the number of Employees\n");
    int n;
    scanf("%d",&n);
    
    while(n!=0){
        int id;
        long long int salary;
        char *name,*dept,*designation,*phn;
        name = (char*)malloc(sizeof(char)*50);
        designation = (char*)malloc(sizeof(char)*50);
        dept = (char*)malloc(sizeof(char)*50);
        phn = (char*)malloc(sizeof(char)*11);
        printf("Enter Employee's Name\n");
        scanf(" %[^\n]",name);
        printf("Enter Employee's designation\n");
        fflush(stdout);
        scanf(" %[^\n]",designation);
        printf("Enter Employee's department\n");
        fflush(stdout);
        scanf(" %[^\n]",dept);
        printf("Enter Employee's Contact number\n");
        fflush(stdout);
        scanf(" %[^\n]",phn);
        printf("Enter the Employee's salary ");
        scanf(" %lld",&salary);
        printf("Enter the Employee's id ");
        scanf(" %d",&id);        
        start =  insertion_at_front(start,id,name,dept,designation,salary,phn);    //using  insertion_at_front() function to create the DLL.
        n--;
    }
    return start;
}


