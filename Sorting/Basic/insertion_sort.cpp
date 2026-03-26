#include <bits/stdc++.h>
using namespace std;
int main()
{
    int array_size;
    cout<<"Enter the size of unsorted array: ";
    cin>>array_size;

    int arr[array_size];
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<array_size; i++)
        cin>>arr[i];

    for(int i=1; i<array_size; i++)
    {
        int item = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>item)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = item;
    }

    cout<<"Final sorted array: ";
    for(int i=0; i<array_size; i++)
        cout<<arr[i]<<" ";
}
