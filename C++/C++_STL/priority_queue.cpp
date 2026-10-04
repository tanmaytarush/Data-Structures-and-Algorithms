/*

* PRIORITY_QUEUE (BASED ON PRIORITY) :-
  - push - O(logN)
  - top - O(1)
  - pop - O(logN)

*/

#include<iostream>
#include<queue>  // Inside queue STL
using namespace std;

void explain_pq()
{
    priority_queue<int> pq;
    pq.push(5); // {5}
    pq.push(2); // {2 5}
    pq.push(8); // {2 5 8}
    pq.emplace(10); // {2 5 8 10}
    
    cout<<pq.top()<<" "; // prints 10 
    pq.pop(); // {8 5}
    cout<<pq.top()<<" "; // prints 8

    // size swap empty functions same as queue

    // Minimum Heap
    priority_queue<int, vector<int>, greater<int>> pq_min;
    pq_min.push(5); // {5}
    pq_min.push(2); // {5 2}
    pq_min.push(8); // {8 5 2}
    pq_min.emplace(10); // {10 8 5 2}
    cout<<pq_min.top()<<" "; // prints 2
}

int main()
{
    cout<<"Priority Queue : "<<endl;
    explain_pq();
    return 0;
}