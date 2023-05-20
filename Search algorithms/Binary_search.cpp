#include <iostream>
#include <math.h>
using namespace std;
int binrseq(int A[],int x,int l,int h)
{
    int m;
    while(l<=h)
    {
        m=(l+h)/2;
        if(A[m]==x)
        {
            return m;
        }
        else if(A[m]>x)
        {
            h=m-1;
        }
        else
        {
            l=m+1;
        }
    }
    return -1;
}
int main()
{
    int A[]= {1,6,8,10,14};
    int l=0,h=4;
    cout<<binrseq(A,8,l,h);

    return 0;
}

