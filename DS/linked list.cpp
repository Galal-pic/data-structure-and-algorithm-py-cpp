#include <iostream>
#include <math.h>
using namespace std;
/// Coders for Programming 01025292509 whatsapp
/*
1- add to right append
2- add to left
3- delete right
4- delete left
5- add to position
6- delete to position
7- count
8- show
9- delete value
10- search_element
11- move_largest_item
12-Delete_All node
13-move_smallest_item
14- delete_elment
15-reverse
16-  delete_elment
*/
struct node
{
    float data;
    node* next;
};
void addto_right(float a,node*& head)
{
    node* newnode=new node; 
    newnode->data=a; 
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        node *newptr;
        newptr=head;
        while(newptr->next!=NULL)
        {
            newptr=newptr->next;
        }
        newptr->next=newnode;
    }
}
void addto_left(float a,node *&head)
{
    node *newnode=new node;
    newnode->data=a;
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
void delete_right(node *&head)
{
    node *newnode = head;
    if(head == NULL)
    {
        cout << "Linked List Empty" << endl;
    }
    else if(head->next == NULL)
    {
        head = NULL;
        delete newnode;
    }
    else
    {
        node *newptr = NULL;
        while(newnode->next != NULL)
        {
            newptr = newnode;
            newnode = newnode->next;
        }
        newptr->next=NULL;
        delete newnode;
    }
}
void delete_left(node *& head)
{
    node *newptr=head;

    if(head==NULL)
        cout<<"this linked_list empty"<<endl;
    else if (head->next==NULL)
    {
        head=NULL;
        delete newptr;
    }
    {
        head=head->next;
        newptr->next=NULL;
        delete newptr;
    }
}
int count_node(node* head)
{
    int c=0;
    if(head==NULL)
        return c;
    else
    {
        node *newptr=head;
        while(newptr!=NULL)
        {
            c++;
            newptr=newptr->next;
        }
    }
    return c;
}
void add_to_pos(float pos,int v,node*& head)
{
    node *newptr=head;
    node *newnode=new node;
    newnode->data=v;
    newnode->next=NULL;
    int x=count_node(head);
    if(pos < 1 || pos > x+1)
    {
        cout << "wrong" << endl;
    }
    else if (pos==1)
        addto_left(v,head);
    else if (pos==x+1)
        addto_right(v,head);
    else
    {
        for(int i=1; i<pos-1; i++)
        {
            newptr=newptr->next;
        }
        newnode->next=newptr->next;
        newptr->next=newnode;
    }
}
void delete_atpos(float pos,node*& head)
{
    node* newptr=head;
    int x=count_node(head);
    if(pos== 1)
        delete_left(head);
    else if(pos==x)
        delete_right(head);
    else
    {
        node* ptr=head;
        /// 1
        for(int i=1; i<pos-1; i++)
        {
            newptr=newptr->next;
        }
        ptr=newptr->next;
        newptr->next=ptr->next;
        ptr->next=NULL;
        delete ptr;
    }
}
void show(node *head)
{
    if(head==NULL)
        cout<<" empty"<<endl;
    else
    {
        node *newptr=head;
        while(newptr != NULL)
        {
            cout << newptr->data << ' ';
            newptr = newptr->next;
        }
        cout << endl;
    }
}
void delete_value(float v,node *&head)
{
    int flag = 0;
    if(head == NULL)
    {
        cout<<" empty"<<endl;
    }
    else
    {
        node *newptr = head;
        node *after = newptr->next;
        if(head->data == v)
        {
            head = head->next;
            delete newptr;
            flag = 1;
        }
        else if(flag == 0)
        {
            while(newptr->next != NULL)
            {
                if(after->data == v)
                {
                    newptr->next = newptr->next->next;
                    after->next= NULL;
                    delete after;
                    flag = 1;
                    break;

                }
                newptr = newptr->next;
                after = newptr->next;
            }
        }

    }
    if(flag == 0)
    {
        cout << "couldn't find value" << endl;
    }
}
int  _search_element(float value,node*&head)
{
    int c =0,flag = 0;
    node *newptr = head;
    if(head==NULL)
        cout<<" empty"<<endl;
    else
    {
        while(newptr != NULL)
        {
            c++;
            if(newptr->data == value)
            {
                return c;
                flag = 1;
                break;
            }
            newptr = newptr->next;
        }
        if (flag == 0)
        {
            cout << "sorry couldn't find element" << endl;
        }
    }
}
void Delete_Allnode( node*& head )
{
    node *newptr=head,*ptr;
    if(head==NULL)
        cout<<"noooooooooooooo"<<endl;
    else if(head->next==NULL)
    {
        head=NULL;
        delete newptr;
    }
    else
    {
        int x=count_node(head);
        for(int i=1; i<=x; i++)
        {
            delete_right(head);
        }
    }
}
void move_largest_item ( node *&head)
{
    float x=count_node(head);
    float y=head->data;
    node* newptr=head;
    while(newptr!=NULL)
    {
        y=max(y,newptr->data);
        newptr=newptr->next;
    }
    int pos=_search_element(y,head);
    delete_atpos(pos,head);
    addto_right(y,head);
}
void move_smallest_item ( node *&head)
{
    float x=count_node(head);
    float y=head->data;
    node* newptr=head;
    while(newptr!=NULL)
    {
        y=min(y,newptr->data);
        newptr=newptr->next;
    }
    int pos=_search_element(y,head);
    delete_atpos(pos,head);
    addto_right(y,head);
}
void _reverse(node*& head) /// if linked list 1 2 3 4 5 if use reverse function 5 4 3 2 1
{
    node* current = head;
    node *prev = NULL, *next = NULL;
    while (current != NULL)
    {
        /// Store next
        next = current->next;

        /// Reverse current node's pointer
        current->next = prev;

        /// Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
}
void delete_elment(int elm,node*& head)
{
    if(head->data==elm)
        delete_left(head);
    else
    {
        node* newptr=head;
        float c=0,t =0;
        while(newptr!=NULL)
        {
            c++;
            if(newptr->data==elm)
            {
                t=1;
                break;
            }
            else
                newptr=newptr->next;
        }
        if(t==0)
            cout<<" not found"<<endl;
        else
            delete_atpos(c,head);
    }
}
void merage_into_sec(node*& head,node*& head2)
{
    node *newptr=head;
    while(newptr->next!=NULL)
    {
        newptr=newptr->next;
    }
    newptr->next=head2;
    head2=NULL;
    delete head2;
}
void delete_node(node*&head,int num)
{
    node* newptr=head;
    if(head==NULL)
        cout<<"this is empty"<<endl;
    else if(head->next==NULL)
    {
        if(newptr->data=num)
        {
            head=NULL;
            delete newptr;
        }
        else
            cout<<"the num "<<num<<"is not exist in this linked list"<<endl;
    }
    else
    {
        node* ptr2=newptr->next;
        while(ptr2!=NULL)
        {
            if(head->data=num)
            {
                head=newptr->next;
                delete newptr;
            }

            else if(ptr2->data=num)
            {
                newptr=ptr2->next;
                delete ptr2;
            }
            else
                newptr=newptr->next;
            ptr2=newptr->next;
        }
        cout<<"the num "<<num<<"is not exist in this linked list"<<endl;
    }
}

int main()
{
    node*Head=NULL;
    addto_right(0,Head);/// 0
    addto_right(1,Head);/// 1
    addto_right(2,Head);/// 2
    add_to_pos(4,3,Head);/// 3
    addto_left(-1,Head);
    show(Head);
    delete_atpos(1,Head);
    show(Head);

    return 0;
}
