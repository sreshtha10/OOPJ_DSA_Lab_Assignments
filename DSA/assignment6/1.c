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
Treenode * minimum(Treenode *root)
{
    if(root == NULL)
        return NULL;
    else if(root->lchild != NULL) // node with minimum value will have no left child
        return minimum(root->lchild); // left most element will be minimum
    return root;
}


Treenode* delete(Treenode*root, int x)
{
    //searching for the item to be deleted
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->rchild = delete(root->rchild, x);
    else if(x<root->data)
        root->lchild = delete(root->lchild, x);
    else
    {
        //No Children
        if(root->lchild==NULL && root->rchild==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->lchild==NULL || root->rchild==NULL)
        {
            Treenode *temp;
            if(root->lchild==NULL){
                temp = root->rchild;
            }
            else{
                temp = root->lchild;
            }
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            Treenode *temp = minimum(root->rchild);
            root->data = temp->data;
            root->rchild = delete(root->rchild, temp->data);
        }
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
            
            default:{
                printf("Invalid Option\n");
                printf("********************\n");
            }
        }
    }
    
    return 0;
}
