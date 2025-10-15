/*

* DE-QUEUE AND STACK :-

*/

#include<iostream>
#include<deque>
#include<stack>
using namespace std;

void explain_deque()
{
    deque<int> dq;
    dq.push_back(3);  // {3}
    dq.emplace_back(4); // {3, 4}
    dq.push_front(2);   // {2, 3, 4}
    dq.emplace_front(1);  // {1, 2, 3, 4}
  
    dq.pop_back();  // {1, 2, 3}
    dq.pop_front();  // {2, 3}

    dq.back();
    dq.front();

    // Rest functions same as of vectors
    // begin, end, rbegin, rend, clear, insert, swap, size

    for(deque<int>::iterator it = dq.begin(); it != dq.end(); ++it)
    {
        cout<<*(it)<<" ";  // Accessing elements via iterator
    }
}


void explain_stack()    // Last-In-First-Out (LIFO)
{
    stack<int> st;
    st.push(1);  // {1}
    st.push(2);  // {2 1}
    st.push(3);  // {3 2 1}
    st.push(4);  // {4 3 2 1}
    st.push(5);  // {5 4 3 2 1}
    st.emplace(6); // {6 5 4 3 2 1}

    cout<<st.top()<<endl; // prints 6 * st[2] access is invalid *
    st.pop(); // st looks like {5 4 3 2 1}
    cout<<st.top()<<endl; // prints 5

    cout<<st.size()<<endl;
    cout<<st.empty()<<endl;

    stack<int> st1, st2;
    st1.swap(st2);
}


int main()
{
    cout<<"Deque : "<<endl;
    explain_deque();
    cout<<"Stack : "<<endl;
    explain_stack();
    return 0;
}