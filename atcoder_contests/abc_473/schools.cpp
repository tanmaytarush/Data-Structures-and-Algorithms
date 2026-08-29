/*

C - Change Schools / 
Time Limit: 2 sec / Memory Limit: 1024 MiB


Score : 
300 points

Problem Statement
Currently, AtCoder High School has 
K classes and 
N students, and the 
i-th 
(1≤i≤N) student belongs to the 
A 
i
​
 -th class.

Takahashi is transferring to AtCoder High School in September. At that time, he can choose any one class among the 
K classes and belong to that class.

He will be sad if there is a class with more students belonging to it than the class he belongs to. Otherwise, he will be happy.

Find how many classes make him happy if he belongs to them.

Constraints
1≤N≤2×10 
5
 
1≤K≤N
1≤A 
i
​
 ≤K (1≤i≤N)
All input values are integers.
Input
The input is given from Standard Input in the following format:

N 
K
A 
1
​
  
A 
2
​
  
… 
A 
N
​
 
Output
Output the number of classes satisfying the condition.

Sample Input 1
Copy
8 5
3 3 5 5 4 4 3 2
Sample Output 1
Copy
3
For example, if Takahashi chooses the fifth class and belongs to it, the number of students belonging to the fifth class becomes 
3. Then, he will be happy since there is no class with more than three students belonging to it.

On the other hand, for example, if he chooses the first class and belongs to it, the number of students belonging to the first class becomes 
1. Then, he will be sad since three students belong to the third class.

He will be happy if and only if he chooses the third, fourth, or fifth class, so output 3.

Sample Input 2
Copy
6 1
1 1 1 1 1 1
Sample Output 2
Copy
1
It is possible that AtCoder High School has only one class.

Sample Input 3
Copy
14 8
6 1 5 3 8 4 3 4 3 5 1 2 5 1
Sample Output 3
Copy
4

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int changeSchools(int n, int k, vector<int>& a) {
        vector<int> freq(k + 1, 0);

        for (int x : a) {
            freq[x]++;
        }

        int mx = 0;
        for (int i = 1; i <= k; i++) {
            mx = max(mx, freq[i]);
        }

        int ans = 0;
        for (int i = 1; i <= k; i++) {
            if (freq[i] + 1 >= mx) {
                ans++;
            }
        }

        return ans;
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Solution sol;
    cout << sol.changeSchools(n, k, a) << '\n';

    return 0;
}