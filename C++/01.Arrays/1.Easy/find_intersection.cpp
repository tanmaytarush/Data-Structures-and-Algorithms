/*

** INTERSECTION OF TWO SORTED ARRAYS :-

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

#include<iostream>
using namespace std;
#include<vector>

vector<int> find_intersectionBF(vector<int> &a1, vector<int> &a2, int n, int m)
{
    vector<int> ans;
    vector<int> visited(m,0);
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            if(a1[i] == a2[j] && visited[j]==0)
            {
                ans.push_back(a2[j]);
                visited[j] = 1;
                break;
            }
            if(a2[j]>a1[i]) 
            {
                break;
            }
        }
    }
    return ans;
}

vector<int> find_instersectionOpt(vector<int> &a1, vector<int> &a2, int n, int m)
{
    int i=0; 
    int j=0;
    vector<int> ans;
    while(i<n && j<m)
    {
        if(a1[i] < a2[j])
        {
            i++;
        }
        else if(a1[i] > a2[j])
        {
            j++;
        }
        else
        {
            ans.push_back(a2[j]);
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    int n;
    int m;
    cin>>n>>m;

    vector<int> a1(n);
    vector<int> a2(m);

    for(int i=0; i<n; ++i)
    {
        cin>>a1[i];
    }

    for(int j=0; j<m; ++j)
    {
        cin>>a2[j];
    }

    vector<int> ans1 = find_intersectionBF(a1, a2, n, m);
    vector<int> ans2 = find_instersectionOpt(a1, a2, n, m);

    for(vector<int>::iterator it = ans1.begin(); it<ans1.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    for(vector<int>::iterator it = ans2.begin(); it<ans2.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}


