#include <bits/stdc++.h>
using namespace std;
int main()
{
    int array_size, search_key, loc=-1;
    cout<<"Enter the size of array: ";
    cin>>array_size;
    int arr[array_size];
    cout<<"Enter the elements of array: ";
    for (int i=0; i<array_size; i++)
        cin>>arr[i];
    cout<<"Enter the search key value: ";
    cin>>search_key;
    int low=0, high=array_size-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]==search_key)
        {
            loc=mid;
            break;
        }
        else if(arr[mid]>search_key)
            high=mid-1;
        else
            low=mid+1;
    }
    if(loc==-1)
        cout<<"Not found"<<endl;
    else
        cout<<search_key<<" is found at position "<<loc+1<<endl;
    main();
}
