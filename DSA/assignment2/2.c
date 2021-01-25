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
}Empl;


Empl *insertion_at_front(Empl* start,int id,char *name,char* dept,char* designation, long long int salary);
Empl  *creation(Empl* start);
void count_print(Empl* start);
Empl* insertion_at_end(Empl* start,int id,char *name,char* dept,char* designation, long long int salary);
Empl *deletion(Empl* start);









