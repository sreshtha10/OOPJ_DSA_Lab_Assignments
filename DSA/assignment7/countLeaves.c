#include<stdio.h>
#include<stdlib.h>


typedef struct treenode{
    int data;
    struct treenode *left;
    struct treenode* right;
}Treenode;  // structure of BST


typedef struct node{
    Treenode* data;
    struct node *next;
}sNode;  // structure for stack 


//stk points to the top of the stack.
sNode * stk = NULL;


//displaying the tree nodes in preorder form.
void preorder(Treenode* ptr){
    if(ptr == NULL){ // Base Case;
        return;
    }
    printf("%d ",ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
}

//inserting the node in the BST
Treenode* insert(Treenode* ptr,int ikey){
    if(ptr == NULL){  // Base case.
        ptr = (Treenode*)malloc(sizeof(Treenode));
        ptr->data = ikey;
        ptr->left = NULL;
        ptr->right = NULL;
    }
    else if(ikey>ptr->data){
        ptr->right = insert(ptr->right,ikey);
    }
    else if(ikey < ptr->data){
        ptr->left = insert( ptr->left,ikey);
        
    }
    else{
        printf("DUPLICATE\n");
    }
    return ptr;
}


//pushing the Treenode in the stack 
void push(Treenode* x){
    sNode * tmp  = (sNode*)malloc(sizeof(sNode));
    if(tmp == NULL){
        printf("Stack Overflow\n");
        return;
    }
    tmp->data = x;
    tmp->next = stk;
    stk = tmp;
    return;
}


// pop function to pop Treenode from the stack 
Treenode *pop(){
    Treenode* x;
    if(stk == NULL){
        printf("Stack Underflow\n");
        return NULL;
    }
    sNode * tmp;
    tmp = stk;
    x = stk->data;
    stk = stk->next;
    free(tmp);
    return x;
}



// isEmpty() will return 0 if stack is empty otherwise return 1
int isEmpty(){
    if(stk == NULL){
        return 0;
    }
    else{
        return 1;
    }
}


//function to count the total number of leaves in the BST 
int countLeaf(Treenode *root)
{
    if(root==NULL)
        return 0;//base case
    push(root);//as root node has children
    int count = 0;//helping variable
    while(isEmpty() != 0)
    {
        Treenode *temp = pop();
        if(temp->left != NULL)
            push(temp->left);
            
        if(temp->right != NULL)
            push(temp->right);
        
        if((temp->left == NULL) && (temp->right==NULL))
            count += 1;//as they are leaf nodes with no children
    }
    
    return count;//no. of leaf nodes
}


//Main function
int main(void){
    Treenode *root = NULL;
    int n,val;
    printf("Enter the number of elements in the BST\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the value of %d node\n",(i+1));
        scanf("%d",&val);
        root = insert(root,val);
    }
    
    printf("Displaying the nodes in preorder form: ");
    preorder(root);
    
    printf("\nTotal number of leaf nodes = %d",countLeaf(root));
    return 0;
}


