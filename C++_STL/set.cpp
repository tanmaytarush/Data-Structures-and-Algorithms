/*

* SET (SORTED AND UNIQUE ELEMENTS) :-
  - Not a linear container, maintains a tree internally
  - Everything happens in log(N) time complexity

*/

#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

void explainSet()
{
    set<int> st;
    st.insert(1); // {1}
    st.insert(2); // {1, 2}
    st.emplace(2); // {1, 2}
    st.insert(4); // {1, 2, 4}
    st.emplace(3); // {1, 2, 3, 4}

    // {1, 2, 3, 4}
    auto it3 = st.find(3); // Returns an iterator

    // {1, 2, 3, 4}
    auto it6 = st.find(6); // Returns the iterator after last element

    st.erase(5); // Erases 5, and takes logarithmic time

    int cnt = st.count(1); // Counts the occurences of 1
    auto it_find3 = st.find(3); // Finds the iterator pointing to 3
    if(it_find3 != st.end())
        st.erase(it_find3); // Erases the iterator pointing to 3

    // {1, 2, 4}
    auto it1 = st.find(2); // startIndex at 2
    auto it2 = st.find(4); // endIndex at 4
    if(it1 != st.end() && it2 != st.end())
        st.erase(it1, it2);  // After erase, {1, 4}

    // lower_bound() and upper_bound() works the same way as in vectors
    auto it_lb = st.lower_bound(2);
    auto it_ub = st.upper_bound(3);
}

void explainMultiSet()
{
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);

    ms.erase(1); // Erases all occurrences of 1
    int cnt = ms.count(1);

    // Erase only one occurrence of 1
    auto it = ms.find(1);
    if(it != ms.end())
        ms.erase(it);

    // Erase a range (if needed, use next() for iterator arithmetic)
    // Example: erase first two occurrences
    ms.insert(1);
    ms.insert(1);
    auto it_start = ms.find(1);
    auto it_end = it_start;
    if(it_start != ms.end()) {
        advance(it_end, 2); // Move iterator forward by 2
        ms.erase(it_start, it_end);
    }
}

void explainUSet()
{
    unordered_set<int> us;
    /*
    The lower_bound and upper_bound functions doesn't work, rest all are the same.
    It does not stores the given element in any particular order. It has a better
    complexity than set in most of the cases, except when collision happens. All 
    operations work in O(1) complexity. 
    */
}

int main()
{
    cout<<"Set : "<<endl;
    explainSet();
    cout<<"Multi-Set : "<<endl;
    explainMultiSet();
    return 0;
}