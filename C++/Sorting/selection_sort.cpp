/*

** SELECTION SORTING :-

- Selection Sorting as the name suggests means that the given minimum element from the
  array is selected as is swapping it in the first position of the array.
- In short it means, Select minimum and Swap.

  - Original -> 13 46 24 52 20 9
  - Step 1   -> (9) 46 24 52 20 13
  - Step 2   -> (9) (13) 24 52 20 46
  - Step 3   -> (9) (13) (20) 52 24 46
  - Step 4   -> (9) (13) (20) (24) 52 46
  - Step 5   -> (9) (13) (20) (24) (46) 52
  - Step 6   -> 9 13 20 24 46 52 (Sorted)

- Generalized Algorithm 

    - Swap at index 0, & minimum index [0, n-1]
    - Swap at index 1, & minimum index [1, n-1]
    - Swap at index 2, & minimum index [2, n-2]
    ......
    ......
    ......
    - Swap at index (n-2), & minimum index [n-2, n-1]

- Pseudo Code:

    for(int i=0; i<n-1, ++i)
    {
        minimum = i;
        for(int j=i, j<n; ++j)
        {
            if(arr[j]<arr[minimum])
                minimum = j;
        }
        int temp = arr[minimum];
        arr[minimum] = arr[j];
        arr[j] = temp;
    }

*/

#include<iostream>
using namespace std;

void selection_sort(int arr[], int n)
{
    for(int i=0; i<n-1; ++i)
    {
        int minimum = i;
        for(int j=i; j<n; ++j)
        {
            if(arr[j]<arr[minimum])
                minimum = j;
        }
        int temp = arr[minimum];
        arr[minimum] = arr[i];
        arr[i] = temp;
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

    selection_sort(arr, n);

    for(int i=0; i<n; ++i)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}


