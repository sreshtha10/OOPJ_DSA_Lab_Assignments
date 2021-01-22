#include<stdio.h>
#include<stdlib.h>


//Insertion
void Insertion(int *array,int index,int element,int n){   
    int temp =  *(array+index);
    int a;
    void *p = realloc(array,sizeof(int)*(n+1));
    if(p != NULL){
        for(int i= index+1;i<n+1;i++)
        {
            a = *(array+i);
            *(array+i) = temp;
            temp = a;
        }
        *(array+index)= element;
        for(int i = 0;i<n+1;i++)
        {
            printf("%d ",*(array+i));
        } 
        printf("\n");
    }
    else{
        printf("Not enough memory available\n");
    }

    
}


//Deletion
void Deletion(int *array,int index,int n)
{
    for(int i = index +1;i<n;i++)
    {
        *(array+i-1)= *(array+i);
    }
    void *p = realloc(array,sizeof(int)*(n-1));
    if(p != NULL){
        for(int i = 0;i<n-1;i++)
        {
            printf("%d ",*(array+i));
        }
        printf("\n");
    }
    else{
        printf("Not enough memory available\n");
    }

}



//Main
int main(){
    printf("Choose from the following\n");
    printf("a.Creating an Array of N Integer Elements\n");
    printf("b. Display of Array Elements with Suitable Heading\n");
    printf("c. Inserting an Element (ELEM) at a given valid Position (POS)\n");
    printf("d. Deleting an Element at a given valid Position (POS)\n");
    printf("e. Exit\n");
    
    
   
    int * array;
    int n = -1; 
    
    while(1){
        char opt;
        scanf("%c",&opt);
        switch(opt){
            case 'a': {
                if (n == -1){
                    printf("Enter the value of n\n");
                    scanf("%d",&n);
                    array =(int*)malloc(sizeof(int)*n);
                    printf("Enter the values\n");
                    for(int i=0;i<n;i++){
                        scanf("%d",array+i);
                    }
                    printf("\n");
                }
                else{  // array is already created.
                    printf("Array already exists\n");
                    }
                    
                printf("****************\n");
                break;
                }
               
            case 'b':{
                if(n == -1){  // array is not created yet.
                    printf("Array is not created\n");
                }
                else{
                    printf("Array is:\n");
                    for(int i =0;i<n;i++){
                        printf("%d ",array[i]);
                    }
                    printf("\n");
                }
                printf("****************\n");
                break;
            }
            
            case 'c':{
                printf("Enter the index at which the element is to be inserted\n");
                int index;
                scanf("%d",&index);
                printf("Enter the element to be inserted\n");
                int element;
                scanf("%d",&element);
                Insertion(array,index,element,n);
                n +=1;
                printf("****************\n");
                break;
            }
            
            
            case 'd':{
                printf("Enter the index of element which is to be deleted\n");
                int index;
                scanf("%d",&index);
                Deletion(array,index,n);
                n -=1;
                printf("****************\n");
                break;
            }
            
            
            case 'e':{
                printf("Exiting the program");
                printf("****************\n");
                exit(0);
            }
        }
    }
    return 0;
}
