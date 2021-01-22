#include<stdio.h>
#include<stdlib.h>


int main(){
    
    int n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int * array = (int*)malloc(sizeof(int)*n);
    if(array == NULL){    
        printf("Memory not available!\n");
        exit(0);
    }
    printf("Enter the array\n");
    for(int i=0;i<n;i++){
        scanf("%d",array+i);
    }
    
    int max = array[0];
    int min = array[0];
    for(int i=1;i<n;i++){
        if(max < *(array+i)){
            max = *(array+i);
        }
        if(min > *(array+i)){
            min = *(array+i);
        }
    }
    
    printf("Maximum element is %d and Minimum element is %d\n",max,min);
    return 0;
}
