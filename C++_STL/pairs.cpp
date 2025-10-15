/*

Four Pillars of Standard Template Library:-
1. Algorithms
2. Containers
3. Functions
4. Iterators

** PAIRS:-

*/

#include<iostream>
using namespace std;

void explain_pair()
{
    pair<int, int> p1 = {1, 3};  // Pair initiation of two elements
    cout<<p1.first<<" "<<p1.second<<endl;

    pair<int, pair<int, int>> p2 = {1, {3, 4}};  // Pair initiation 
    cout<<p2.first<<" "<<p2.second.second<<" "<<p2.second.first<<endl;

    pair<int, int> arr[] = {{1,2}, {3,4}, {5,6}};
    cout<<arr[1].second;
}

int main()
{
    explain_pair();
    return 0;
}