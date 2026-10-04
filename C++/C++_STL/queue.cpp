/*

* QUEUE (FIRST IN FIRST OUT) :-

*/

#include<iostream>
#include<queue>
using namespace std;

void explain_queue()
{
    queue<int> q;
    q.push(1); // {1}
    q.push(2); // {2 1}
    q.emplace(3); // {3 2 1}

    q.back() += 5; // (last element in queue)+5
    cout<<q.back()<<endl; // prints 5+3 = 8

    // queue is {8 2 1}
    cout<<q.front()<<endl; // prints 1
    q.pop(); // queue is {8 2}
    cout<<q.front()<<endl; // prints 2
}

int main()
{
    cout<<"Queue elements : "<<endl;
    explain_queue();
    return 0;
}