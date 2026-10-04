/*

Problem statement
Given that integers are read from a data stream. Your task is to find the median of the elements read so far.

Median is the middle value in an ordered integer list. If the size of the list is even there is no middle value. So the median is the floor of the average of the two middle values.

For example :
[2,3,4] - median is 3.
[2,3] - median is floor((2+3)/2) = 2.


Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
1 <= N <= 10^4
0 <= data <= 10^8
Where T is the number of test cases, N is the number of elements in the data stream.

Time Limit : 1 sec
Sample Input 1:
3
3
1 2 3 
2
9 9 
1
4 
Sample Output 1:
1 1 2
9 9 
4 
Explanation for Sample Input 1:
For test case 1 
After reading first element of stream , Median of [1] is 1 
After reading second element of stream, Median of [1, 2]  = floor((1+2)/2)  = 1
After reading third element of stream, Median of [1,2,3] = 2
So the output will be 1 1 2.
Sample Input 2:
2
3
5 3 8
2
3 8
Sample Output 2:
5 4 5
3 5
Explanation for Sample Input 2:
For test case 1 
After reading first element of stream, Median of [5] is 5
After reading second element of stream, Median of [5, 3]  = floor((5+3)/2)  = 4
After reading third element of stream, Median of [5,3,8] = 5 , it is the middle value of the sorted array
So the output will be 5 4 5.
C++ (g++ 5.4)
10111213141516171819202122232425262728293031323334353637383940414243987644
		callMedian(arr[i], maxHeap, minHeap, median);
		ans.push_back(median);
	}

	return ans;
}

Last saved at 6:29 PM

*/

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;


int signum(int a, int b)
{
	if(a == b) return 0;
	else if(a > b) return 1;
	else return -1;
}

void callMedian(int &element, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap,
				int &median)
{
	switch(signum(maxHeap.size(), minHeap.size()))
	{
		case 0:
		if(element > median)
		{
			minHeap.push(element);
			median = minHeap.top();
		}
		else
		{
			maxHeap.push(element);
			median = maxHeap.top();
		}
		break;


		case 1:
		if(element < median)
		{	
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap.push(element);
			median = (minHeap.top() + maxHeap.top()) / 2;
		}
		else
		{
			minHeap.push(element);
			median = (minHeap.top() + maxHeap.top()) / 2;
		}
		break;

		case -1:
		if(element < median)
		{
			maxHeap.push(element);
			median = (minHeap.top() + maxHeap.top()) / 2;
		}
		else
		{
			maxHeap.push(minHeap.top());
			minHeap.pop();
			minHeap.push(element);
			median = (minHeap.top() + maxHeap.top()) / 2;
		}
		break;
	}
}

vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	vector<int> ans;
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int median = 0;

	for(int i=0; i<n; ++i)
	{
		callMedian(arr[i], maxHeap, minHeap, median);
		ans.push_back(median);
	}

	return ans;
}


int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    vector<int> ans = findMedian(arr, n);

    for(vector<int> :: iterator it = ans.begin(); it != ans.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}
