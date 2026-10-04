/*

Backtracking print 1 to n

*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    void print1toN(int i, int n)
    {
        if(i>n)
        {
            return;
        }

        //cout<<i<<" ";
        print1toN(i+1, n);
        cout<<i<<" "; 
    }
};

int main()
{
    Solution sol;

    int n;
    cin>>n;

    sol.print1toN(1, n);
    
    return 0;
}