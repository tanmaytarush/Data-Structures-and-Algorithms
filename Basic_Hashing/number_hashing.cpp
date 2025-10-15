/*

** NUMBER HASHING THROUGH MAP/UNORDERED-MAP:-

    - In array hashing we had to declare an array of size equal to the exact size of the 
      elements in the input.
    - But in map, we have an advantage of storing the given unique elements only in the 
      manner of key and values. Therefore, space complexity reduces many folds.

*/

#include<iostream>
#include<map>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    // pre-compute
    map<int, int> mpp; // If used unordered_map, then order will be not be the same
    // So in unordered_map, the time complexity is in the range of constant O(1).
    for(int i=0; i<n; ++i)
    {
        mpp[arr[i]]++;
    }

    // Iterator fetch
    for(auto it : mpp)
    {
        cout<<it.first<<"->"<<it.second<<endl;
    }

    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        // fetch
        cout<<mpp[n]<<endl;
    }
}