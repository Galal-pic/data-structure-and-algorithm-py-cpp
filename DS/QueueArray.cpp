# queue array
#include <iostream>

using namespace std;
const int n=100;
int queue[n];
int front=-1;
int rear=-1;
void insert()
{
    if(rear==n-1)
        cout<<"overflow";
    else
    {
        if(front==-1)
            front=0;
        int v;
        cin>>v;
        rear++;
        queue[rear]=v;
    }
}
void del()
{
    if(front ==-1||front>rear)
        cout<<"underflow";
    else
    {
        cout<<queue[front]<<endl;
        front++;
    }

}
void display()
{
    if(front==-1||front>rear)
        cout<<"empty";
    else
    {

        for(int i=front; i<=rear; i++)
            cout<<queue[i]<<" ";
    }
}
int main()
{
    
    return 0;
}
