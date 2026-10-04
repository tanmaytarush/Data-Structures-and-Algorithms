/*
Question:
Given a set of N jobs where each job 'i' has a deadline and profit associated with it. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. We earn the profit associated with a job if and only if the job is completed by its deadline. Find the number of jobs done and the maximum profit.

Example:
Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with a maximum profit of 60 (20+40).

Approach:
- We create a vector of pairs 'jobs' to store the profit and deadline of each job.
- We sort the 'jobs' vector in non-increasing order of profits.
- We initialize a vector 'deadline' of size 'n+1' and set all elements to -1.
- We also initialize variables 'ans' and 'cnt' to 0.
- We iterate over the 'jobs' vector.
  - For each job, we get the deadline and profit.
  - We check from the deadline to 1 (in reverse order) if there is any slot available to schedule the job.
  - If we find an available slot, we mark it as scheduled by setting 'deadline[dead]' to 1, increment 'cnt' and add the profit to 'ans'.
- Finally, we return a vector containing 'cnt' and 'ans' as the number of jobs done and the maximum profit.

Complexity Analysis:
- The time complexity of this approach is O(NlogN), where N is the number of jobs.
- This is due to the sorting operation on the 'jobs' vector based on profits.
- The space complexity is O(N) as we use additional vectors to store the jobs and deadlines.

Code:
*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Job
{
    public:
    int id;
    int deadline;
    int profit;

    Job(int id, int deadline, int profit)
    {
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

class JobScheduler
{
    public:
    pair<int, int> jobSequence(vector<Job> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end(), compare);

        // get the maximum value for hash array for getting max-profits
        int maxDeadline = nums[0].deadline;
        for(int i=0; i<n; ++i)
        {
            maxDeadline = max(maxDeadline, nums[i].deadline);
        }

        // get total profits and deadlines reached
        vector<int> hash(maxDeadline+1, -1);
        int profits = 0;
        int countJobs = 0;
        for(int i=0; i<n; ++i)
        {
            // could be replaced with union-find disjoint set
            for(int j=nums[i].deadline; j>0; j--)
            {
                if(hash[j] == -1)
                {
                    // assign the slot
                    hash[j] = i;
                    // count
                    countJobs++;
                    // add profits
                    profits += nums[i].profit;
                break;
                }
            }
        }
        return make_pair(countJobs, profits);
    }
};

int main()
{
    JobScheduler job;
    int n;
    cin>>n;

    vector<Job> nums;
    for(int i=0; i<n; i++)
    {
        int id, deadline, profit;
        cin>>id>>deadline>>profit;
        nums.push_back(Job(id, deadline, profit));
    }

    pair<int, int> ans = job.jobSequence(nums);

    cout<<ans.first<<" "<<ans.second<<endl;

    return 0;
}