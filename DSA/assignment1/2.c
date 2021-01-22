#include<stdio.h>
#include<stdlib.h>
 
 
//Length function
int length(char string[]){
    int count = 0;
    for(int i=0;string[i]!='\0';i++){
        count++;
    }
    return count;
}

// Replace function to modify the string in case any pattern is found.
void replace(char string[], char r_string[],int start,int end){
    int j =0;
    for(int i = start-1;i<end;i++,j++){
        string[i] = r_string[j];
    }
    return;
}


//Main
int main(){
    
    char string[100],p_string[100],r_string[100];
    printf("Enter the string\n");
    gets(string);
    printf("Enter the pattern string\n");
    gets(p_string);
    printf("Enter the replace string\n");
    gets(r_string);
    
    int p_length = length(p_string);    // length of p_string
    int r_length = length(r_string);
    int occurence = 0;    // number of occurence of the pattern string
    int p = 0;
    
    
    while(string[p] != '\0'){
        
        int start,end; 
        int i=p,j = 0;
        
        for(;p_string[j]!='\0';i++,j++){
            if(string[i] == p_string[j]){
                continue;
            }
            else{
                break;
            }
        }
        
        //if j equals p_length this means a pattern is found in the original string.
        if(j == p_length){
            end = i;
            start = i-r_length+1;
            replace(string,r_string,start,end);
            occurence += 1;
        }
        p+= 1;
    }
    
    if(occurence == 0){  // if occurence is 0, there will not be any replacement in the original string.
        printf("No %s pattern found\n",p_string);
    }
    else{
        printf("%d, %s pattern found\n",occurence,p_string);
        printf("Modified string = %s\n",string);
    }
    
   
    
    return 0;
}
