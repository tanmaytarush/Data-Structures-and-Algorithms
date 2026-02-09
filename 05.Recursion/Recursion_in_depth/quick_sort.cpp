#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j)
    {
        while(arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        while(arr[j] > pivot && j >= low + 1)
        {
            j--;
        }

        if(i < j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]); // swap low with j
    return j;
}

void qS(vector<int> &arr, int low, int high)
{
    if(low < high)
    {
        int pIndex = partition(arr, low, high);
        qS(arr, 0, pIndex - 1);
        qS(arr, pIndex + 1, high);
    }
}

vector<int> quickSort(vector<int> &arr, int n)
{
    qS(arr, 0, n - 1);
    return arr;
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    vector<int> result = quickSort(arr, n);

    for(vector<int>::iterator it = result.begin(); it != result.end(); ++it)
    {
        cout<<*it<<" ";
    }

    return 0;
}