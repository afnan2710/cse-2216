#include <bits/stdc++.h>
using namespace std;
int main()
{
    int array_size;
    bool found = false;
    cout<<"Enter the size of array: ";
    cin>>array_size;
    int arr[array_size];
    cout<<"Enter the elements of array: ";
    for (int i=0; i<array_size; i++)
        cin>>arr[i];
    int search_key;
    cout<<"Enter your search key: ";
    cin>>search_key;
    for (int i=0; i<array_size; i++)
    {
        if (arr[i]==search_key)
        {
            cout<<search_key<<" is found at position "<<i+1<<endl;
            found=true;
            break;
        }
    }
    if(!found)
        cout<<"Not found";
}
