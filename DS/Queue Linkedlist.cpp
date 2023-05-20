#queue linked list
#include <iostream>

using namespace std;
struct node
{
    int item;
    node *next=NULL;
};
node *front=NULL,*rear=NULL;
void insert()
{
    node *Nnode=new node;
    int v;
    cin>>v;
    Nnode->item=v;
    if(rear==NULL)
    {
        rear=Nnode;
        front=rear;

    }
    else
    {
        rear->next=Nnode;
        rear=rear->next;

    }

}
void del()
{
    if(front ==NULL)
        cout<<"empty";
    else
    {
        node *ptr=front;
        front=front->next;
        delete ptr;
    }
}
void display()
{
     if(front ==NULL)
        cout<<"empty";
        else
        {
            node *ptr=front;
            while(ptr!=NULL)
            {
                cout<<ptr->item<<" ";
                ptr=ptr->next;
            }
        }

}
int main()
{
    insert();
    insert();
    insert();
    insert();
    insert();
    display();
    return 0;
}
