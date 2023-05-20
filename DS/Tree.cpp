#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node *leftChild;
    struct node *rightChild;
};
node*root=NULL;
void insert(int data)
{
    node *tempNode = new node;
    node *current;
    node *parent;
    tempNode->data = data;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;
    if(root == NULL)
    {
        root = tempNode;
    }
    else
    {
        current = root;
        parent = NULL;
        while(1)
        {
            parent = current;
            if(data < parent->data)
            {
                current = current->leftChild;
                if(current == NULL)
                {
                    parent->leftChild = tempNode;
                    return;
                }
            }
            else
            {
                current = current->rightChild;
                if(current == NULL)
                {
                    parent->rightChild = tempNode;
                    return;
                }
            }
        }
    }
}
struct node* search(int data)
{
    struct node *current = root;
    cout<<"Visiting elements: ";
    while(current->data != data)
    {
        if(current != NULL)
            cout<< current->data;
        if(current->data>data)
        {
            current=current->leftChild;
        }
        else
        {
            current=current->rightChild;

        }
        if(current==NULL)
        {
            return NULL;
        }
    }
    return current;
}
void pre_order_traversal(struct node* root)
{
    if(root != NULL)
    {
        cout<<root->data;
        pre_order_traversal(root->leftChild);
        pre_order_traversal(root->rightChild);
    }
}
}
void inorder_traversal(struct node* root)
{
    if(root != NULL)
    {
        inorder_traversal(root->leftChild);
        cout<<root->data<<endl;
        inorder_traversal(root->rightChild);
    }
}
void post_traversal(struct node* root)
{
    if(root != NULL)
    {
        post_traversal(root->leftChild);
        post_traversal(root->rightChild);
        cout<<root->data<<endl;

    }
}
int main()
{
    return 0;
}

