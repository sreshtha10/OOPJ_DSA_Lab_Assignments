/*Implement a menu driven Program in C for the following operations on Doubly Linked List (DLL) of Employee Data with the fields: emp ID , Name, Dept, Designation, Sal, PhNo 
a. Create a DLL of N Employees Data by using end insertion. 
b. Display the status of DLL and count the number of nodes in it 
c. Perform Insertion and Deletion at End of DLL 
d. Perform Insertion and Deletion at Front of DLL 
e. Exit
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int id;
    char *name;
    char *dept;
    char *designation;
    long long int salary;  //employee sal may be very high, that's why I'm using long long int.
    struct node* next;
    struct node* prev;
}Empl;


//function declaration
Empl *insertion_at_front(Empl* start,int id,char *name,char* dept,char* designation, long long int salary);
Empl  *creation(Empl* start);
void count_print(Empl* start);
Empl* insertion_at_end(Empl* start,int id,char *name,char* dept,char* designation, long long int salary);
Empl *deletion(Empl* start);




//Main function
int main(){
    printf("Choose from the following:\n");
    printf("1. Create a DLL of N Employees Data by using end insertion \n2. Display and Count the total number of Employees \n3. Insertion at end \n4. Deletion at end\n5. Exit");
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
                int id;
                long long int salary;
                char *name,*dept,*designation;
                name = (char*)malloc(sizeof(char)*50);
                designation = (char*)malloc(sizeof(char)*50);
                dept = (char*)malloc(sizeof(char)*100);
                printf("Enter Employee's Name\n");
                scanf(" %[^\n]",name);
                printf("Enter Employee's designation\n");
                fflush(stdout);
                scanf(" %[^\n]",designation);
                printf("Enter Employee's department\n");
                fflush(stdout);
                scanf(" %[^\n]",department);
                printf("Enter the Employee's salary ");
                scanf(" %lld",&salary);
                printf("Enter the Employee's id ");
                scanf(" %d",&id);
                start = insertion_at_end(start,id,name,dept,designation,salary);
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
        printf("Id:  %d  Name :  %s   Department  %s   Designation %s  Salary %lld \n",p->id,p->name,p->dept,p->designation,p->salary);
        p = p->next;
        count++;
    }
    printf("Total Employees: %d\n",count);
    return;
}







