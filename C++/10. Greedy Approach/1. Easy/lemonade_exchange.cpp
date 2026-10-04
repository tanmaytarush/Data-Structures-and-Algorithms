/*
Question:
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills).
Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
Note that you do not have any change in hand at first.
Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

Example:
Input: bills = [5, 5, 5, 10, 20]
Output: true
Explanation:
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.

Approach:
- We maintain two counters: `fiveCnt` to count the number of $5 bills and `tenCnt` to count the number of $10 bills we have.
- We iterate over the bills array.
- For each bill, we check if it is $5, $10, or $20.
  - If it is $5, we increment the `fiveCnt`.
  - If it is $10, we increment the `tenCnt` and decrement the `fiveCnt` since we need to give back a $5 bill as change.
  - If it is $20, we try to give back a $10 bill and a $5 bill as change if we have them. Otherwise, we try to give back three $5 bills.
- After each transaction, we check if the `fiveCnt` is negative, which means we have given a $5 bill that we actually don't have. In this case, we return false.
- If we successfully process all the bills without any negative `fiveCnt`, we return true.

Complexity Analysis:
- The time complexity of this approach is O(N), where N is the length of the bills array.
- We iterate over the bills array once to process each bill.
- The space complexity is O(1) as we are using only a constant amount of extra space.

Code:
*/


#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

class LemonadeExchange
{
    public:
    bool lemonadeExchange(vector<int>&bills)
    {
        int n = bills.size();
        int five = 0;
        int ten = 0;
        for(int &bill : bills)
        {
            if(bill == 5)
            {
                five += 1;
            }
            else if(bill == 10)
            {
                if(five)
                {
                    ten += 1;
                    five -= 1;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(five && ten)
                {
                    five -= 1;
                    ten -= 1;
                }
                else if(five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    LemonadeExchange lE;
    int n;
    cin>>n;

    vector<int> bills(n);
    for(int i=0; i<n; ++i)
    {
        cin>>bills[i];
    }

    bool result = lE.lemonadeExchange(bills);

    cout<<result<<endl;

    return 0;
}