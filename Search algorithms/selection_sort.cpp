/// selection sort &and complexity o(n^2)
#include <iostream>
using namespace std;
void selection_sort(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        for(int q=i+1; q<n; q++)
        {
            if(arr[i]>arr[q])
            {
                int z=arr[i];
                arr[i]=arr[q];
                arr[q]=z;
                /// swap
            }
        }
    }
}
int main()
{
    int arr[]={5,3,2,8,1};
    selection_sort(arr,5);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }


    return 0;
}
