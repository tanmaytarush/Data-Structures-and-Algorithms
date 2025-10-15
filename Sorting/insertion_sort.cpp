/*

** INSERTION SORTING :-

- Takes an element and places it at correct position. Just like playcards.

    - Original -> 14 9 15 12 6 8 13
    - Step 1   -> 14 (If this is the array size, then correct position)
    - Step 2   -> 9 14 (Corrected order for size 2)
    - Step 3   -> 9 14 15 (Corrected order for size 3)
    - Step 4   -> 9 12 14 15 (Corrected order for size 4)
    - Step 5   -> 6 9 12 14 15 (Corrected order for size 5)
    - Step 6   -> 6 8 9 12 14 15 (Corrected order for size 6)
    - Step 7   -> 6 8 9 12 13 14 15 (Corrected order for complete array)

- Algorithm 

    for(int i=0; i<n; ++i)
    {
        int j=i;
        while(j>0 && arr[j]<arr[j-1])
            swap(arr[j], arr[j-1]);
            j--;
    }

*/


#include<iostream>
using namespace std;

void insertion_sort(int arr[], int n)
{
    for(int i=0; i<n; ++i) 
    {
        int j=i; // Dynamic size increase till complete array size reaches
        while(j>0 && arr[j]<arr[j-1]) // Loop until at correct position 
        {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }
    insertion_sort(arr, n);
    for(int i=0; i<n; ++i)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}