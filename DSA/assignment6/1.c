#include<stdio.h>
#include<stdlib.h>

typedef struct treenode{
    int data;
    struct treenode *lchild;
    struct treenode* rchild;
}Treenode;


// traversal : preorder, inorder, postorder.

void preorder(Treenode* ptr){
    if(ptr == NULL){ // Base Case;
        
        return;
    }
    printf("%d ",ptr->data);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}

void inorder(Treenode* ptr){
    if(ptr == NULL){
        return;
    }
    inorder(ptr->lchild);
    printf("%d ",ptr->data);
    inorder(ptr->rchild);
}

void postorder(Treenode* ptr){
    if(ptr == NULL){
        return;
    }
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d ",ptr->data);
}



/* searching - * if the key = element, element is found.
               * if the key < element, search in left subtree
               * if the key > element, search in the right subtree.
               * if the pointer reaches NULL ie the end of the tree, element is not in the BST.
               
*/

Treenode* search(Treenode* root,int element){ 
    if(root == NULL){
        return NULL; // element not found 
    }
    if(root->data == element){
        return root;
    }
    else if(element > root->data){
        search(root->rchild,element);
    }
    else{
        search(root->lchild,element);
    }
}

//insertion
Treenode* insert(Treenode* ptr,int ikey){
    if(ptr == NULL){  // Base case.
        ptr = (Treenode*)malloc(sizeof(Treenode));
        ptr->data = ikey;
        ptr->lchild = NULL;
        ptr->rchild = NULL;
    }
    else if(ikey>ptr->data){
        ptr->rchild = insert(ptr->rchild,ikey);
    }
    else if(ikey < ptr->data){
        ptr->lchild = insert( ptr->lchild,ikey);
        
    }
    else{
        printf("DUPLICATE\n");
    }
    return ptr;
}

/* deletion - case 1.  Node to be deleted is a leaf
              case 2. Node to be deleted has only 1 child.
              case 3. Node to be deleted has 2 child.
    */
    
Treenode* delete(Treenode* root,int dkey){
    Treenode* ptr = root,*par = NULL;
    while(ptr != NULL){
        if(dkey == ptr->data){
            break;
        }
        par = ptr;
        if(dkey > ptr->data){
            ptr = ptr->rchild;
        }
        else{
            ptr = ptr->lchild;   
        }
    }
    if(ptr == NULL) // element not found
    {
        printf("%d not found in the BST\n",dkey);
        return root;
    }
    else if(ptr->lchild == NULL && ptr->rchild == NULL){ // no child.
        // case 1
        if(par == NULL){ // root node to be deleted
            root = NULL;
        }
        else if(par->lchild == ptr){
            par->lchild = NULL;
        }
        else{
            par->rchild = NULL;
        }
        free(ptr);
        return root;
    }
    else if(ptr->lchild == NULL || ptr->rchild == NULL){ // one child.
        // case 2.
        if(par == NULL){ // ptr is root node
            if(ptr->lchild != NULL){
                root = ptr->lchild;
                free(ptr);
                return root;
            }
            else{
                root = ptr->rchild;
                free(ptr);
                return root;
            }
        }
        else if(ptr == par->lchild){
            if(ptr->lchild != NULL){
                par->lchild = ptr->lchild;
                free(ptr);
                return root;
            }
            else{
                par->lchild = ptr->rchild;
                free(ptr);
                return root;
                
            }
        }
        else{
            if(ptr->lchild != NULL){
                par->rchild = ptr->lchild;
                free(ptr);
                return root;
            }
            else{
                par->rchild = ptr->rchild;
                free(ptr);
                return root;
                
            }
        }
        
    }
    else{ // node to be deleted has two childs.
        // case 3.
        int x;
        Treenode* tmp = ptr->rchild,*tmp2 = ptr->rchild;
        while(tmp->lchild != NULL){
            tmp2 = tmp;
            tmp = tmp->lchild;
        }
        x = tmp->data;
        tmp2->lchild = NULL;
        free(tmp);
        ptr->data = x;
        if(par == NULL){
            root = ptr;
        }
        return root;
    }
    
    
    return root;
}


int main(void){
    Treenode *root = NULL;
    printf("Choose from the following:\n");
    printf("1. Insertion\n2. Deletion\n3. Preorder Traversal\n4. Inorder Traversal\n5. Postorder Traversal\n6. Exit\n");
    printf("********************\n");
    int opt,val;
    while(1){
        scanf("%d",&opt);
        switch(opt){
            
            case 1:{
                printf("Enter the value to be Inserted\n");
                scanf("%d",&val);
                root = insert(root,val);
                printf("********************\n");
                break;
            }
            
            case 2:{
                printf("Enter the value of node to be deleted\n");
                scanf("%d",&val);
                root = delete(root,val);
                printf("********************\n");
                break;
            }
            
            case 3:{
                preorder(root);
                printf("\n********************\n");
                break;
            }
            
            case 4:{
                inorder(root);
                printf("\n********************\n");
                break;
            }
            
            case 5:{
                postorder(root);
                printf("\n********************\n");
                break;
            }
            
            case 6:{
                //Exit
                exit(0);
            }
        }
    }
    
    return 0;
}
