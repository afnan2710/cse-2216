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

    int inversion_count = 0;
    for(int i=0; i<array_size-1; i++)
    {
        bool swapped = false;
        for(int j=0; j<array_size-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                inversion_count++;
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }

    cout<<"Total inversion count: "<<inversion_count<<endl;
    cout<<"Final sorted array: ";
    for(int i=0; i<array_size; i++)
        cout<<arr[i]<<" ";
}
