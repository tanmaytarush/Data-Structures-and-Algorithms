/*
QUESTION:-
Union of two arrays can be defined as the common and distinct elements in the two arrays.
Given two sorted arrays of size n and m respectively, find their union.


Example 1:

Input:
n = 5, arr1[] = {1, 2, 3, 4, 5}
m = 3, arr2 [] = {1, 2, 3}
Output: 1 2 3 4 5
Explanation: Distinct elements including
both the arrays are: 1 2 3 4 5.


Example 2:

Input:
n = 5, arr1[] = {2, 2, 3, 4, 5}
m = 5, arr2[] = {1, 1, 2, 3, 4}
Output: 1 2 3 4 5
Explanation: Distinct elements including
both the arrays are: 1 2 3 4 5.
*/

/*
APPROACH:-
-> Take two pointer i and j where i is for arr1 and j is for arr2 and traverse
-> While travsersing 3 cases arises
    -> arr1[ i ] == arr2[ j ]
        Here we found a common element, so insert only one element in the union.
        Let’s insert arr[i] in union and whenever we insert element we increment pointer while pointer is not equal to the inserted element
    -> arr1[i]<arr2[j]
        Here insert arr[i]
    -> arr1[i]>arr2[j]
        Here insert arr2[j]
-> Now check if elements of any array is left to traverse then traverse that array
*/

// CODE:-
#include<iostream>
using namespace std;
#include<vector>
#include<set>

vector<int> unionArraysBF(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    set<int> st;
    vector<int> Union;
    for(int i=0; i<n; ++i)
    {
        st.insert(arr1[i]);
    }
    for(int j=0; j<m; ++j)
    {
        st.insert(arr2[j]);
    }
    for(auto it : st)
    {
        Union.push_back(it);
    }
    return Union;
}

vector<int> unionArraysOpt(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    int i=0;
    int j=0;
    vector<int> Union;

    while(i<n && j<m)
    {
        if(arr1[i] <= arr2[j])
        {
            if(Union.size()==0 || Union.back()!=arr1[i])
            {
                Union.push_back(arr1[i]);
                i++;
            }
        }
        else
        {
            if(Union.size()==0 || Union.back()!=arr2[j])
            {
                Union.push_back(arr2[j]);
                j++;
            }
        }
    }

    while(i<n)    
    {
        if(Union.size()==0 || Union.back()!=arr1[i])
        {
            Union.push_back(arr1[i]);
            i++;
        }
    }

    while(j<m)
    {
        if(Union.size()==0 || Union.back()!=arr2[j])
        {
            Union.push_back(arr2[j]);
            j++;
        }
    }

    return Union;
}

int main()
{
    int n; 
    int m;
    cin>>n>>m;
    
    vector<int> arr1(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr1[i];
    }

    vector<int> arr2(m);
    for(int i=0; i<m; ++i)
    {
        cin>>arr2[i];
    }

    vector<int> UnionBF = unionArraysBF(arr1, arr2, n, m);
    vector<int> UnionOpt = unionArraysOpt(arr1, arr2, n, m);

    for(auto &it : UnionBF)
    {
        cout<<it<<" ";
    }

    for(auto &it : UnionOpt)
    {
        cout<<it<<" ";
    }

    return 0;
}

// TIME COMPLEXITY = O(N+M)
// SPACE COMPLEXITY = O(0)