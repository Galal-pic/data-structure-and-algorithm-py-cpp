#include <iostream>
using namespace std;
int pivot(int a[], int first, int last)
{
    cout<<first<<" bb "<<last<<endl;
    int p = first;
    int pivotElement = a[first];
    for(int i = first+1 ; i <= last ; i++)
    {
        if(a[i] <= pivotElement)
        {
            p++;
            cout<<i<<" "<<p<<endl;;
            swap(a[i], a[p]);
        }
    }
                cout<<first<<" fb "<<p<<endl;;
    swap(a[p], a[first]);
      for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
        cout<<endl;
    return p;
}
void quickSort( int a[], int first, int last)
{
    int pivotElement;
    if(first < last)
    {
        pivotElement = pivot(a, first, last);
        quickSort(a, first, pivotElement-1);
        quickSort(a, pivotElement+1, last);
    }
}


int main()
{
    int test[] = { 5,3,4,1,2 };
    int N = sizeof(test)/sizeof(int);
    quickSort(test, 0, N-1);

    return 0;
}
