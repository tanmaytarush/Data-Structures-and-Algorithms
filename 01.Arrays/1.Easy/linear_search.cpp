/*
I don't think anyone needs it's solution. The idea is to traverse the array using loop and when the element
is equal to k return the same
*/

#include<iostream>
using namespace std;
#include<vector>

int linearSearch(vector<int> &arr, int element)
{
    int n = arr.size();
    int i;
    for(i=0; i<n; ++i)
    {
        if(arr[i] == element)
        {
            break;
        }
    }
    return i;
}

int main()
{
    int n;
    cin>>n;

    int element; 
    cin>>element;

    vector<int> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    int index = linearSearch(arr, element);
    cout<<index;

    return 0;
}