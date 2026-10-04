/*
QUESTION:
Design an algorithm to calculate the span of a stock's price for the current day based on the price history.

APPROACH:
To solve this problem, we can use a stack to store the prices along with their corresponding spans.
1. Initialize an empty stack and a variable to keep track of the current day (let's call it 'cnt').
2. For each price, do the following:
   - While the stack is not empty and the price at the top of the stack is less than or equal to the current price, pop elements from the stack.
   - Calculate the span for the current price using the following formula:
     - If the stack is empty, the span is cnt + 1.
     - Otherwise, the span is cnt - stack.top().second, where stack.top().second represents the day corresponding to the price at the top of the stack.
   - Push the current price along with its span (pair<int, int>) onto the stack.
   - Increment the 'cnt' variable.
3. Return the calculated spans.

Example:
Input: [100, 80, 60, 70, 60, 75, 85]
Output: [1, 1, 1, 2, 1, 4, 6]


INTUITION BRUTE FORCE :-

1.  Consider an input array which contains a list of numbers and we need to find out maximum count for 
    which a list of stock values represented by each element is less than the current day.

2.  Now the extreme brute force approach would be to move from the end inside the input array and find
    out the consecutive elements less than the current, increasig current count by 1 each time.

3.  The moment we wind an element which is greater than the current iterating backwards, we simply 
    break the loop and move towards next iteration.

4.  Whatever might be the curr value after that iteration will be returned.


INTUITION OPTIMIZED :-

1. Instead of checking elements one by one in backward direction, we optimize using a stack.

2. The stack stores pairs of (price, span), where:
   - price = stock price
   - span = number of consecutive days this price dominates

3. For each incoming price:
   - Initialize span = 1 (current day itself)
   - While stack is not empty and top price <= current price:
        - Add the span of the top element to current span
        - Pop the stack

4. This way, instead of checking each previous element individually,
   we "jump" over multiple elements using stored spans.

5. Finally, push the current (price, span) into stack and return span.

6. Each element is pushed and popped at most once → O(N) total time.

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

class StockSpannerBF
{
    public:
    vector<int> arr;

    StockSpannerBF()
    {

    }

    int next(int price)
    {
        arr.push_back(price);
        int count = 1;
        stack<int> st;
 
        for(int i=arr.size() - 2; i>=0; --i)
        {
            if(arr[i] <= price) count++;
            else break;
        }

        return count;
    }
}; 

class StockSpannerOpt
{
    public:
    stack<pair<int, int>> st; // {price, span}

    StockSpannerOpt() {}

    int next(int price)
    {
        int span = 1;

        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});

        return span;
    }
};


int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> prices[i];
    }

    // Brute Force
    StockSpannerBF sbf;
    vector<int> result;

    for (int price : prices)
    {
        result.push_back(sbf.next(price));
    }

    for (int x : result)
    {
        cout << x << " ";
    }

    cout << endl;

    // Optimized
    StockSpannerOpt sopt;
    vector<int> result2;

    for (int price : prices)
    {
        result2.push_back(sopt.next(price));
    }

    for (int x : result2)
    {
        cout << x << " ";
    }

    return 0;
}

/*
COMPLEXITY ANALYSIS:
- The time complexity for each 'next' operation is O(1) on average because each price is pushed and popped from the stack at most once.
- The space complexity is O(n), where n is the number of prices, because the stack can store at most n elements.
*/

