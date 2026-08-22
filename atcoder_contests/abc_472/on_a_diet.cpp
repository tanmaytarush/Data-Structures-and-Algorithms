/*

Takahashi is staying at his parents' house for an 
N-day homecoming trip.

At his parents' house, a snack is prepared every day, and the calorie count of the snack on day 
i is 
A 
i
​
 .

To manage his health, he repeats the following: he eats the snack on a given day if and only if the total calorie count of the snacks he has eaten in the most recent 
M days does not exceed 
K.

Specifically, in the order 
i=1,2,…,N, he decides whether to eat the snack on day 
i according to the following rule:

Assuming that he eats the snack on day 
i, if the total calorie count of the snacks eaten from day 
max(i−M+1,1) through day 
i is at most 
K, then he actually eats the snack on day 
i. Otherwise, he does not eat the snack on day 
i.
For each 
i=1,2,…,N, determine whether Takahashi eats the snack on day 
i.

Sample Input 1
Copy
5 3 83
48 73 59 90 21
Sample Output 1
Copy
Yes
No
No
No
Yes
For each day, assuming that he eats the snack, the total calorie count of the snacks eaten in the most recent three days is as follows:

Day 
1: 
48
Day 
2: 
48+73=121
Day 
3: 
48+59=107
Day 
4: 
90
Day 
5: 
21

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    void solve(vector<long long>&A, int n, int m, long long k)
    {
        vector<long long> eaten(n, 0);
        long long sum = 0;

        for(int i=0; i<n; i++)
        {
            if(i-m >= 0)
            {
                sum -= eaten[i-m];
            }

            if(sum + A[i] <= k)
            {
                eaten[i] = A[i];
                sum += A[i];
                cout<<"Yes"<<"\n";
            }
            else
            {
                eaten[i] = 0;
                cout<<"No"<<"\n";
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    int n, m;
    long long k;
    cin>>n>>m>>k;

    vector<long long> A(n);
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }

    sol.solve(A, n, m, k);

    return 0;
}