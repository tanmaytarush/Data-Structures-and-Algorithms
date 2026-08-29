/*

Output all length-
N sequences 
A=(A 
1
​
 ,A 
2
​
 ,…,A 
N
​
 ) consisting of non-negative integers that satisfy 
i=1
∑
N
​
 i×A 
i
​
 =K, in lexicographic order from smallest to largest.

Here, you will only receive inputs such that the number of sequences satisfying the condition is at most 
3×10 
5
 .

*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

class Solution
{
    public:
    void dfs(int N, int K, vector<int>&A, int idx, int rem)
    {
        if(idx > N)
        {
            if(rem == 0)
            {
                for(int i=1; i<=N; i++)
                {
                    cout<<A[i]<<(i==N ? '\n' : ' ');
                }
            }
            return;
        }

        for(int take = 0; take <= rem/idx; ++take)
        {
            A[idx] = take;
            dfs(N, K, A, idx+1, rem - idx * take);
        }
    }
};

int main()
{
    Solution sol;
    int n, k;
    cin >> n >> k;

    vector<int> A(n + 1, 0);
    sol.dfs(n, k, A, 1, k);

    return 0;
}