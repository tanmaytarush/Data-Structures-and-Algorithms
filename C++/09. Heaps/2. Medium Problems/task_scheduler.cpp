/*
QUESTION:
Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

APPROACH:
To minimize the total time, we need to consider the task with the maximum frequency. Let's assume the maximum frequency is maxfreq. The CPU will need at least (maxfreq - 1) intervals of cooldown time between the executions of the tasks with the maximum frequency.

1. Create a frequency map to count the occurrences of each task.
2. Find the maximum frequency maxfreq.
3. Calculate the total number of intervals required by multiplying (maxfreq - 1) with the cooldown period n.
4. Iterate through the frequency map and count the number of tasks with the maximum frequency. Add this count to the total number of intervals.
5. Return the maximum of the total number of intervals and the total number of tasks.

The leastInterval function implements this approach.

TIME COMPLEXITY:
The time complexity of the leastInterval function is O(N), where N is the number of tasks. We iterate through the tasks twice: once to calculate the frequencies and find the maximum frequency, and once to count the number of tasks with the maximum frequency. Both iterations take O(N) time.

SPACE COMPLEXITY:
The space complexity is O(1) because the frequency map has a fixed number of unique tasks (26 lowercase letters).
*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    int leastInterval(vector<char>&tasks, int n)
    {
        vector<int> mp(26, 0);
        for(char ch : tasks)
        {
            mp[ch-'A']++;
        }

        priority_queue<int> pq;
        for(int i=0; i<26; ++i)
        {
            if(mp[i]>0)
            {
                pq.push(mp[i]);
            }
        }

        int time = 0;
        while(!pq.empty())
        {
            vector<int>temp;
            for(int i=1; i<=n+1; ++i){
                if(!pq.empty())
                {
                    int top = pq.top();
                    pq.pop();
                    top--;
                    temp.push_back(top);
                }
            }

            for(int &f : temp)
            {
                if(f>0) pq.push(f);
            }

            if(pq.empty())
            {
                time += temp.size();
            }
            else
            {
                time += (n+1);
            }
        }

        return time;
    }
};

int main()
{
    Solution sol;
    int n;
    cin>>n;
    vector<char> tasks(n);

    for(int i=0; i<n; ++i)
    {
        char ch;
        cin>>ch;
        tasks[i] = ch;
    }

    int m;
    cin>>m;

    int result = sol.leastInterval(tasks, m);

    cout<<result<<endl;

    return 0;
}
