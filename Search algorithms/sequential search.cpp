#include <iostream>
#include <math.h>
using namespace std;
int seq(int A[],int n, int x)
{
    for(int i=0; i<n; i++)
    {
        if(A[i]==x)
            return i;
    }
    return -1;
}
int main()
{
    int A[]={5,8,3,1,6};
    cout<<seq(A,5,3);
    return 0;
}

