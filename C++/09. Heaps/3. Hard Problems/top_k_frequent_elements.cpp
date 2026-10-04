/*
Question:
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/

/*
Approach:
1. Create a frequency map to count the occurrences of each element in the array.
2. Use a min heap to store the k most frequent elements based on their frequencies.
3. Iterate through the frequency map and push elements into the min heap.
4. If the size of the min heap exceeds k, remove the element with the lowest frequency.
5. Finally, extract the elements from the min heap and return them in reverse order to get the k most frequent elements.
*/

/*
Complexity Analysis:
- The time complexity is O(N log K), where N is the size of the input array nums. Building the frequency map takes O(N) time, and inserting and removing elements from the min heap take O(log K) time, which is done for each element in nums.
- The space complexity is O(N) to store the frequency map and O(K) for the min heap, resulting in a total of O(N + K) space.

CODE:-
*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

class node
{
    public:
    int data;
    int frequency;

    node(int data, int frequency)
    {
        this->data = data;
        this->frequency = frequency;
    }
};

/*
std::priority_queue<T,Container,Compare> should return true when 'a' has lower priority 
than 'b' (i.e., a should come after b). top() returns the element with highest priority 
(the one that other elements do not compare greater than).
*/
class compare
{
    public:
    bool operator()(node *a, node *b)
    {
        return a->frequency > b->frequency;
    }
};

class Solution
{
    public:
    vector<int> topKElements(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> freq;
        priority_queue<node*, vector<node*>, compare> pq;
        vector<int> ans;

        for(int &num : nums)
        {
            freq[num]++;
        }

        for(auto &it : freq)
        {
            pq.push(new node(it.first, it.second));

            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        while(!pq.empty())
        {
            ans.push_back(pq.top()->data);
            pq.pop();
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    int k;
    cin>>k;

    vector<int> ans = sol.topKElements(arr, k);

    reverse(ans.begin(), ans.end());

    for(vector<int> :: iterator it = ans.begin(); it != ans.end(); ++it)
    {
        cout<<*it<<" ";
    }

    return 0;
}
