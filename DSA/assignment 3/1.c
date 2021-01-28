#include<stdlib.h>
#include<stdio.h>

typedef struct node{
    int info;
    struct node* link;
}Node;


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
    while(1){
        scanf("%d",&opt);
        switch(opt){
            case 1:{
                
                
                printf("******************************");
                break;
            }
            
            case 2:{
                
                
                printf("******************************");
                break;
            }
            
            case 3:{
                
                
                printf("******************************");
                break;
            }
            
            case 4:{
                
                
                printf("******************************");
                break;
            }
            
            case 5:{
                
                printf("******************************");
                break;
            }
            
            case 6:{
                
                
                printf("******************************");
                break;
            }
            
            case 7:{
                
                
                printf("******************************");
                break;
            }
            
            case 8:{
                
                
                printf("******************************");
                break;
            }
            
            default :{
                printf("Invalid Option\n");
                printf("******************************");
            }
        }
    }
    
    
}
