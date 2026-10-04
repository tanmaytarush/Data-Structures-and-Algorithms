#include<iostream>
#include<stack>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; ++i)
    {
        arr[i] = temp[i - low];
    }
}

void mS(vector<int> &arr, int low, int high)
{
    if(low >= high) return;
    int mid = low + (high - low) / 2;
    mS(arr, 0, mid); // either mid+1 to mid or otherwise
    mS(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void mergeSort(vector<int> &arr, int n)
{
    mS(arr, 0, n-1);
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

    mergeSort(arr, n);

    for(vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
    {
        cout<<*it<<" ";
    }

    return 0;
}

