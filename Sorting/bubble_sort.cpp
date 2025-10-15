/*

** BUBBLE SORTING :-

- Bubble Sorting refers to the process of sorting in which the given element is compared with 
  adjacent elements and the maximum one comes to the last.
- Push maximum element to the last by adjacent swaps.
- Bubble meaning the heavy one comes to the bottom.

    - Original -> 13 9 46 52 23 47 (Adjacent Swaps)
    - Step 1   -> 9 13 46 23 47 52
    - Step 2   -> 9 13 23 46 47 52

- Algorithmic Approach
    - Swap at index 0 and 1 & so on, till (n-1)
    - Swap at index 0 and 1 & so on, till (n-2)
    - Swap at index 0 and 1 & so on, till (n-3)
    ......
    ......
    ......
    - Swap at index 0 and 1 & so on, till 1

- Pseudo Code
    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<i; ++j)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }


*/


#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i=n-1; i>=0; --i)
    {
        for(int j=0; j<=i-1; ++j)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void bubbleSort_optimized(int arr[], int n) // If already ascending, then O(N)
{
    for(int i=n-1; i>=0; --i)
    {
        for(int j=0; j<=i-1; ++j)
        {
            int swapped = 0;
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
            if(swapped == 0)
            {
                break;  // Breaks if all arranged
            }
            cout<<"Runs\n";
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
    bubbleSort(arr, n);
    bubbleSort_optimized(arr, n);
    for(int i=0; i<n; ++i)
    {
        cout<<arr[i]<<" ";
    }
}