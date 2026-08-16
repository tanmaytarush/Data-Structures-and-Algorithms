/*

Score : 
400 points

Problem Statement
There is a charger with an unlimited number of charging slots. At time 
0, all slots are empty.

The maximum capacity of a battery is 
V. While a battery is plugged into a slot, it is charged at a rate of 
1 until its charge level reaches the maximum capacity (that is, the charge level increases by 
1 for every 
1 unit of time that passes).

Process 
Q queries in order. The 
q-th query is given in one of the following formats. Here, it is guaranteed that 
t 
1
​
 <⋯<t 
Q
​
 .

Type 
1 (
1 t 
q
​
  w 
q
​
 ): At time 
t 
q
​
 , plug one battery with charge level 
w 
q
​
  into a slot.
Type 
2 (
2 t 
q
​
 ): At time 
t 
q
​
 , unplug one battery with the highest charge level from its slot, and output that battery's charge level. If there is no battery plugged into any slot, output 
−1 instead.
Constraints
1≤Q≤3×10 
5
 
1≤V≤10 
9
 
For type 
1 queries, 
1≤t 
q
​
 ≤10 
9
 .
For type 
1 queries, 
0≤w 
q
​
 ≤V.
For type 
2 queries, 
1≤t 
q
​
 ≤10 
9
 .
t 
1
​
 <⋯<t 
Q
​
 
The input values are all integers.
Input
The input is given from Standard Input in the following format:

Q 
V
query 
1
​
 
⋮
query 
Q
​
 
Here, 
query 
q
​
  represents the 
q-th query, and is given in one of the following two formats:

1 
t 
q
​
  
w 
q
​
 
2 
t 
q
​
 
Output
Let 
x be the number of type 
2 queries. Output 
x lines.

The 
k-th line (
1≤k≤x) should contain the value to be outputed for the 
k-th type 
2 query.

Sample Input 1
Copy
7 100
1 15 60
1 25 80
2 30
1 45 0
2 60
2 70
2 80
Sample Output 1
Copy
85
100
25
-1
The seven queries are processed in the following order.

At time 
15, a battery with charge level 
60 is plugged in. At this point, the charger has a battery with charge level 
60.
At time 
25, a battery with charge level 
80 is plugged in. At this point, the charger has batteries with charge levels 
70,80.
At time 
30, the charger has batteries with charge levels 
75,85. Of these, the battery with charge level 
85 is unplugged.
At time 
45, a battery with charge level 
0 is plugged in. At this point, the charger has batteries with charge levels 
0,90.
At time 
60, the charger has batteries with charge levels 
15,100. Of these, the battery with charge level 
100 is unplugged.
At time 
70, the charger has a battery with charge level 
25. This battery, with charge level 
25, is unplugged.
At time 
80, no battery is plugged into the charger. Thus, no battery is unplugged.
Sample Input 2
Copy
20 380736236
1 21873985 256702097
2 86369729
1 114301317 288304981
1 147244640 305840435
2 150951976
1 331581391 50335458
1 352989552 47577202
1 400130024 345362760
2 458793150
2 509082216
1 591375600 197371572
1 617022014 101276068
1 679649471 310249627
1 796351653 268586022
1 825648347 129608152
2 908069704
2 921770319
1 949684819 372272469
1 971850999 335461408
2 986253026
Sample Output 2
Copy
321197841
324955640
380736236
380736236
380736236
380736236
380736236


*/


#include <iostream>
#include <set>
using namespace std;

int main()
{
    int Q;
    long long V;

    cin >> Q >> V;

    multiset<long long> batteries;

    for (int q = 0; q < Q; q++)
    {
        int type;
        long long t;

        cin >> type >> t;

        if (type == 1)
        {
            long long w;
            cin >> w;

            // Effective charge at time 0
            long long value = w - t;

            batteries.insert(value);
        }
        else
        {
            if (batteries.empty())
            {
                cout << -1 << '\n';
                continue;
            }

            // Maximum effective charge
            auto it = prev(batteries.end());

            long long value = *it;

            // Actual charge at time t
            long long charge = value + t;

            // Battery cannot exceed V
            charge = min(charge, V);

            cout << charge << '\n';

            batteries.erase(it);
        }
    }

    return 0;
}