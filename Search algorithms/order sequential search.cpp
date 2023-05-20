#include <iostream>
#include <math.h>
using namespace std;
int orderseq(int A[],int n, int x)
{
    int pos=0;
    bool stop=false;
    bool found=false;
    while(pos<n&&stop==false&&found==false)
    {
        if(A[pos]==x)
            found=true;
        else if(A[pos]>x)
            stop=true;
        else
            pos=pos+1;
    }
    return found;
}
int main()
{
    int A[]= {1,2,3,4,8};
    /// return 1 if found
    cout<<orderseq(A,5,3);

    return 0;
}


