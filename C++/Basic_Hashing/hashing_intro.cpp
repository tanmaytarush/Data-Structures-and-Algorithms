/*

** HASHING :-

    - prestoring and fetching
    - freq[256] array is a similar use case of hashing

*/

#include<iostream>
using namespace std;

// When declared hash globally it takes values uptill 10^7

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    // precompute 
    int hash[13] = {0}; // Maximum range of value is 10^6
    for(int i=0; i<n; ++i)
    {
        hash[arr[i]] += 1;
    }

    int q;
    cin>>q;
    while(q--)
    {
        int number;
        cin>>number;
        // fetch
        cout<<hash[number]<<endl;
    }
    return 0;
}