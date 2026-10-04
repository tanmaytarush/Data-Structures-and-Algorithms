/*
Question:
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
*/

/*
Approach:
1. Use two priority queues: a max heap to store the smaller half of the numbers and a min heap to store the larger half of the numbers.
2. When adding a new number:
   - If the max heap is empty or the number is smaller than the top element of the max heap, push it into the max heap.
   - Otherwise, push it into the min heap.
   - Balance the heaps by transferring the top element of the larger heap to the smaller heap if the size difference between the heaps exceeds 1.
3. When finding the median:
   - If the sizes of the heaps are equal, calculate the average of the top elements of both heaps.
   - Otherwise, return the top element of the heap with a larger size.
Complexity Analysis:

The time complexity for adding a number to the MedianFinder is O(log N), where N is the total number of elements added so far. This is because we need to maintain the two heaps and balance them if necessary, which takes logarithmic time.
The time complexity for finding the median using the findMedian() function is O(1). This is because we directly access the top elements of the heaps, which takes constant time.
The space complexity is O(N), where N is the total number of elements added. This is because we need to store the elements in the two priority queues.

CODE:-

*/
    
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class MedianFinder{
public:
    int signum(int a, int b)
    {
        if(a == b) return 0;
        else if(a > b) return 1;
        else return -1;
    }

    void callMedian(int &element, priority_queue<int> &maxi, 
        priority_queue<int, vector<int>, greater<int>> &mini, int &median)
    {
        switch(signum(maxi.size(), mini.size()))
        {
            case 0: 
                if(element > median)
                {
                    mini.push(element);
                    median = mini.top();
                }
                else
                {
                    maxi.push(element);
                    median = maxi.top();
                }
            break;

            case 1:
                if(element > median)
                {
                    mini.push(element);
                    median = (mini.top() + maxi.top())/2;
                }
                else
                {
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(element);
                    median = (mini.top() + maxi.top())/2;
                }
            break;

            case -1:
                if(element > median)
                {
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(element);
                    median = (mini.top() + maxi.top())/2;
                }
                else
                {
                    maxi.push(element);
                    median = (mini.top() + maxi.top())/2;
                }
            break;
        }
    }

    vector<int> findMedian(vector<int> &nums, int n)
    {
        vector<int> ans;
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int median = 0;

        for(int i=0; i<n; ++i)
        {
            callMedian(nums[i], maxHeap, minHeap, median);
            ans.push_back(median);
        }
        return ans;
    }
};


int main()
{
    MedianFinder mf;
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0; i<n; ++i)
    {
        cin>>nums[i];
    }

    vector<int> ans = mf.findMedian(nums, n);

    for(vector<int>::iterator it = ans.begin(); it != ans.end(); ++it)
    {
        cout<<*it<<endl;
    }

    return 0;
}