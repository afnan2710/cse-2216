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

    for(int i=0; i<array_size-1; i++)
    {
        int min_index = i;
        for (int j=i+1; j<array_size; j++)
        {
            if (arr[j]< arr[min_index])
                min_index = j;
        }
        if (min_index != i)
            swap(arr[i],arr[min_index]);
    }

    cout<<"Final sorted array: ";
    for(int i=0; i<array_size; i++)
        cout<<arr[i]<<" ";
}
