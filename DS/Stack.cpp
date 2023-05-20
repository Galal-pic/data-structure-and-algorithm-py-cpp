#include <iostream>
#include<cmath>
using namespace std;
#define MAX 10
struct stack
{
    int top=-1;
    char arr[MAX];
};
bool isempty(stack s)
{
    if(s.top==-1)
        return true;
    else
        return false;
}
bool isfull(stack s)
{
    if(s.top==MAX-1)
        return true;
    else
        return false;
}
void push(stack &s,char n)
{
    if(isfull(s))
        cout<<"FULL STACK"<<endl;
    else
    {

        s.top++;
        s.arr[s.top]=n;
    }
}
void pop(stack &s)
{
    if(isempty(s))
        cout<<"empty"<<endl;
    else
    {
        s.top--;
    }
}
void show(stack s)
{
    if(isempty(s))
        cout<<"empty"<<endl;
    else
    {
        for(int i=s.top; i>=0; i--)
            cout<<s.arr[i]<<" ";
        cout<<endl;
    }
}
bool pir(char x,char y)
{
    if(x=='['&&y==']')
        return true;
    else if(x=='{'&&y=='}')
        return true;
    else if(x=='('&&y==')')
        return true;
    return false;
}
//***************************************************************************************

bool isbalanc(stack& s,string x)
{
    for(int i=0; i<x.size(); i++)
    {
        if(x[i]=='('||x[i]=='{'||x[i]=='[')
            push(s,x[i]);
        else if(x[i]==')'||x[i]=='}'||x[i]==']')
        {
            if(isempty(s) ||!pir(s.arr[s.top],x[i]))
                return false;
            else
                pop(s);
        }
    }
    if(isempty(s))
        return true;
    else
        return false;
}
//*****************************************************************************
float trans(char x)
{
    float val=x-'0';
    return val;
}
bool isoperand(char x)
{
    if(x>='0'&&x<='9')
        return true;
    else
        return false;
}
bool isoperator(char x)
{
    if((x=='+')||(x=='-')||(x=='*')||(x=='/')||(x=='^'))
        return 1;
    return 0;
}
float opertion(int x,int y,char q)
{
    if(q=='+')
        return x+y;
    else if (q=='-')
        return x-y;
    else if (q=='*')
        return x*y;
    else if (q=='/')
        return x-y;
    else if (q=='^')
        return pow(x,y);
}
float postfix(string x)
{
    stack s;
    float a,b;
    for(int i=0; i<x.size(); i++)
    {
        if(isoperator(x[i]))
        {
            a=s.arr[s.top];
            pop(s);
            b=s.arr[s.top];
            pop(s);
            push(s,opertion(a,b,x[i]));
        }
        else if(isoperand(x[i]))
        {
            push(s,trans(x[i]));

        }
    }
    return s.arr[s.top];
}
int main()
{
    string x="124/";
    cout<<  postfix(x);
    return 0;
}

