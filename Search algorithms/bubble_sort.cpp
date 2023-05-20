#include <iostream>
using namespace std;
void bubble_sort(int arr[],int n)
{
    int flag=0,c=0;
    for(int i=0; i<n-1; i++)
    {
        for(int q=0; q<n-i-1; q++)
        {
            if(arr[q]>arr[q+1])
            {
                //swap(arr[q],arr[q+1])
                int z=arr[q+1];
                arr[q+1]=arr[q];
                arr[q]=z;
            }
            c++;
        }
        if(flag==1)
            break;
    }
    cout<<"number of path " <<c<<endl;

}
int main()
{
    int arr[]= {5,6,4,0,1};
    bubble_sort(arr,5);
    for(int i=0; i<5; i++)
        cout<<arr[i]<<" ";
    return 0;
}
