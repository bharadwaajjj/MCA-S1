#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node* right;
}Node;

Node *root = NULL;

void traverse(Node *);
void insert();
void delete();
Node* search(int val);
int noChildren(Node *temp);
Node* parentof(Node *temp);
Node* successor(Node *temp);

int main()
{
    int ch;
    while(1)
    {
        printf("\nEnter your choice\n1)Insert\n2)Delete\n3)Traversal\n4)Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                printf("\nInorder Traversal : ");
                traverse(root);
                break;
            case 4:
                return 0;
            default:
                printf("\nInvalid Choice !!\n");
        }
    }
    return 0;
}

void traverse(Node *root){
    if(root==NULL)
    {
        return;
    }
    traverse(root->left);
    printf(" %d ->",root->data);
    traverse(root->right);
}

void insert(){
    int item;
    printf("Enter the data :");
    scanf("%d",&item);
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = item;
    newnode->left = NULL;
    newnode->right = NULL;
    if(root == NULL)
    {
        root = newnode;
    }
    else{
        Node *temp = root;
        Node *parent;
        while(temp!= NULL)
        {
            parent = temp;
            if(newnode->data > temp->data){
                temp=temp->right;
            }
            else{
                temp=temp->left;
            }
        }
        if(newnode->data > parent->data)
        {
            parent->right = newnode;
        }
        else{
            parent->left = newnode;
        }
    }
}

void delete()
{
    int item,children;
    Node *loc,*temp,*parent,*success;
    printf("Enter the element you want to delete :");
    scanf("%d",&item);
    loc = search(item);
    if(loc != NULL)
    {
        children = noChildren(loc);
        parent = parentof(loc);
        if(loc == parent)//node to be deleted is root node
        {
            if(children==0){
                temp = loc;
                root = NULL;
                free(temp);
            }
            else if(children == 1){
                temp = loc;
                if(root->right!=NULL)
                {
                    root = root->right;
                }
                else{
                    root = root->left;
                }
                free(temp);
            }
            else{
                temp = loc;
                success = successor(loc);
                Node *success_parent = parentof(success);
                root = success;
                root->left = loc->left;

                if(success_parent == loc){
                    root->right = success->right;
                }
                else{
                    success_parent->left = success->right;
                    root->right = loc->right;   
                }
                free(temp);
            }
        }
        else{
            if(children == 0)
            {
                temp = loc;
                if(parent->left == temp)
                {
                    parent->left = NULL;
                }
                else{
                    parent->right = NULL;
                }
                free(temp);
            }
            else if(children == 1)
            {
                Node *activeChildren;
                temp = loc;
                if(loc->left != NULL){
                    activeChildren = loc->left;
                }
                else{
                    activeChildren = loc->right;
                }

                if(parent->left == loc)
                {
                    parent->left = activeChildren;
                }else{
                    parent->right = activeChildren;
                }
                free(temp);
            }
            else
            {
                Node *success_parent;
                success = successor(loc);
                success_parent = parentof(success);

                // Replace `loc` with `success`
                if (parent->left == loc)
                    parent->left = success;
                else
                    parent->right = success;

                // Update `success` children pointers carefully
                if (success_parent != loc)
                {
                    if (success_parent->left == success)
                        success_parent->left = success->right;
                    else
                        success_parent->right = success->right;

                    success->right = loc->right;
                }

                success->left = loc->left;

                free(loc);
            }
        }
        
    }
    else{
        printf("\nElement not found in BST\n");
    }
}

Node* search(int val)
{
    Node *temp = root;
    while(temp!=NULL){
        if(temp->data == val)
        {
            break;
        }
        else if(temp->data > val)
        {
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return temp;
}

int noChildren(Node *temp){
    int num=0;
    if(temp->right != NULL)
    {
        num+=1;
    }
    if(temp->left != NULL)
    {
        num+=1;
    }
    return num;
}

Node* parentof(Node *temp){
    Node *temp1 = root;
    Node *parent = root;
    while(temp1->data != temp->data)
    {
        parent = temp1;
        if(temp1->data > temp->data)
        {
            temp1=temp1->left;
        }
        else
        {
           temp1=temp1->right; 
        }
    }
    return parent;
}

Node* successor(Node *temp){
    Node *temp1 = temp;
    temp1 = temp1->right;
    while(temp1->left != NULL){
        temp1=temp1->left;
    }
    return temp1;
}