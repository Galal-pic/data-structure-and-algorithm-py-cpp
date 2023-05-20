#include <iostream>
using namespace std;
void insertion_sort(int arr[],int n)
{
    int key,q;
    for(int i=1; i<n; i++)
    {
        key=arr[i];
        q=i-1;
        while(q>=0&&arr[q]>key)
        {
            arr[q+1]=arr[q];
            q--;
        }
        arr[q+1]=key;
    }
}
int main()
{
    int arr[]= {2,4,5,1,0};
    insertion_sort(arr,5);
    for(int i=0; i<5; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
