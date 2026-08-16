/*

C - Cookies and Greedy Takahashi / 
Time Limit: 2 sec / Memory Limit: 1024 MiB


Score : 
300 points

Problem Statement
There are cookies at 
N positions on a number line. The coordinate of the 
i-th cookie is 
A 
i
​
 .

Takahashi is initially at coordinate 
0 on the number line, and repeats the following action until he has picked up all 
N cookies.

Action: Move to the coordinate of the nearest cookie from his current position (if there are multiple such cookies, the one with the smallest coordinate), and pick up that cookie.
Find the total distance Takahashi travels until he picks up all the cookies.

Constraints
1≤N≤3×10 
5
 
−10 
9
 ≤A 
i
​
 ≤10 
9
 
A 
i
​
 

=0
The 
A 
i
​
  are distinct.
All input values are integers.
Input
The input is given from Standard Input in the following format:

N
A 
1
​
  
… 
A 
N
​
 
Output
Output the answer.

Sample Input 1
Copy
4
-1 -4 2 -11
Sample Output 1
Copy
23
Takahashi acts as follows.

He moves from coordinate 
0 to coordinate 
−1 and picks up the cookie. The distance traveled is 
1.
He moves from coordinate 
−1 to coordinate 
−4 and picks up the cookie. The distance traveled is 
3.
He moves from coordinate 
−4 to coordinate 
2 and picks up the cookie. The distance traveled is 
6.
He moves from coordinate 
2 to coordinate 
−11 and picks up the cookie. The distance traveled is 
13.
Thus, the total distance traveled is 
1+3+6+13=23.

In the second action, the distances to the cookie at coordinate 
−4 and the cookie at coordinate 
2 are both 
3, and Takahashi moves to 
−4, the smaller coordinate.

Sample Input 2
Copy
10
1 2 3 4 5 -1 -2 -3 -4 -6
Sample Output 2
Copy
17

*/

#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
using namespace std;

long long greedyCookies(int n, vector<long long>& coordinates)
{
    set<long long> cookies(coordinates.begin(), coordinates.end());

    long long currentPoint = 0;
    long long total = 0;

    while (!cookies.empty())
    {
        // First cookie >= currentPoint
        auto right = cookies.lower_bound(currentPoint);

        // Cookie immediately to the left
        auto left = right;

        if (left != cookies.begin())
            --left;
        else
            left = cookies.end();

        // No cookie on the left
        if (left == cookies.end())
        {
            total += abs(*right - currentPoint);
            currentPoint = *right;
            cookies.erase(right);
        }

        // No cookie on the right
        else if (right == cookies.end())
        {
            total += abs(*left - currentPoint);
            currentPoint = *left;
            cookies.erase(left);
        }

        // Cookies on both sides
        else
        {
            long long leftDistance = currentPoint - *left;
            long long rightDistance = *right - currentPoint;

            // Tie -> smaller coordinate -> left
            if (leftDistance <= rightDistance)
            {
                total += leftDistance;
                currentPoint = *left;
                cookies.erase(left);
            }
            else
            {
                total += rightDistance;
                currentPoint = *right;
                cookies.erase(right);
            }
        }
    }

    return total;
}

int main()
{
    int n;
    cin >> n;

    vector<long long> coordinates(n);

    for (int i = 0; i < n; i++)
        cin >> coordinates[i];

    cout << greedyCookies(n, coordinates) << '\n';

    return 0;
}