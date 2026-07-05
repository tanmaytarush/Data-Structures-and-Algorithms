/*
Question:
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?
Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Example:
Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] = {2,4,6,7,9,9}
Output: 4
Explanation: Maximum four meetings can be held with the given start and end timings.
The meetings are - (1, 2), (3, 4), (5, 7), and (8, 9)

Approach:
- We store the meetings as pairs of (end[i], start[i]) in a vector.
- We sort the vector in non-decreasing order based on the end time of meetings.
- We initialize the answer as 1 and the previous meeting end time as the end time of the first meeting in the sorted vector.
- We iterate over the meetings starting from the second meeting.
  - If the start time of the current meeting is greater than the previous meeting end time, we increment the answer and update the previous meeting end time.
- Finally, we return the answer.

Complexity Analysis:
- The time complexity of this approach is O(NlogN), where N is the number of meetings.
- Sorting the meetings based on the end time takes O(NlogN) time.
- The space complexity is O(N) as we store the meetings in a vector.

Code:
*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

class meeting
{
    public:
    int start;
    int end;
    int pos;

    meeting(int s, int e, int p)
    {
        this->start = s;
        this->end = e;
        this->pos = p;
    }
};

bool compare(const meeting &d1, const meeting &d2)
{
    if (d1.end != d2.end) return d1.end < d2.end;
    return d1.pos < d2.pos;
}

class Solution
{
    public:
    vector<int> nMeeting(vector<int>&start, vector<int>&end)
    {
        int n = start.size();
        vector<meeting> data_struct;
        for(int i=0; i<n; ++i)
        {
            data_struct.push_back({start[i], end[i], i+1});
        }

        sort(data_struct.begin(), data_struct.end(), compare);

        vector<int> result;
        int prev = data_struct[0].end;
        result.push_back(data_struct[0].pos);

        for(int i=1; i<n; ++i)
        {
            if(data_struct[i].start > prev)
            {
                result.push_back(data_struct[i].pos);
                prev = data_struct[i].end;
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;

    int n;
    cin>>n;

    vector<int> start(n);
    for(int i=0; i<n; ++i)
    {
        cin>>start[i];
    }

    vector<int> end(n);
    for(int i=0; i<n; ++i)
    {
        cin>>end[i];
    }

    vector<int> result = sol.nMeeting(start, end);

    for(vector<int>::iterator it = result.begin(); it != result.end(); ++it)
    {
        cout<<*it<<" ";
    }

    return 0;
}