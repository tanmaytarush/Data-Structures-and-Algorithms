/*

** VECTORS AND LISTS(FRONT OPERATIONS AS WELL) :-

- Whenever we would want to store elements at contiguous locations, we usually declare
  an array. But if we want to modify that contiguous memory with elements, we use Vectors.

*/

#include<iostream>
#include<vector>   // Include vector STL
#include<list>   // Include list STL
using namespace std;

void explain_vectors()
{
    vector<int> v;   // Creates an empty container {}
    v.push_back(1);   // Adds 1 as first element to the vector
    v.emplace_back(2);   // Similar to push_back, adds an element

    vector<pair<int, int>> vec;
    vec.push_back({1,2});   // Stores {{1,2}}
    vec.emplace_back(1,2);  // Emplace automatically detects push_back data format

    vector<int> v100(5, 100);  // Generates {100, 100 ,100 ,100 ,100}
    vector<int> v0(5);   // Generates {0, 0, 0, 0, 0}

    vector<int> v1(5, 20);   // Generates {20, 20, 20, 20, 20}
    vector<int> v2(v1);    // Another container, copy of v1

    /*
    Accessing elements in a vector through iterators
    */

    vector<int> :: iterator it_begin = v.begin();  // Memory of first element
    it_begin++;
    cout<<*(it_begin)<<" ";  // Dereferencing the value
    it_begin = it_begin + 2;
    cout<<*(it_begin)<<" ";

    vector<int> :: iterator it_end = v.end();   // Last Element
    vector<int> :: reverse_iterator it_rend = v.rend();  // begin++ element iteration
    vector<int> :: reverse_iterator it_rbegin = v.rbegin();  // end-- element iteration

    cout<<v[0]<<" "<<v.at(0);
    if(!v.empty())
    {
        cout<<v.back()<<" ";
    }

    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout<<*(it)<<endl;
    }

    for(auto it = v.begin(); it != v.end(); ++it) // auto keyword automatically detects type
    {
        cout<<*(it)<<endl;
    }

    for(auto val : v)   // automatic iterator detection for vector v
    {
        cout<<val<<endl;
    }

    if(v.size() > 1)
    {
        // {10, 12, 20, 15}
        v.erase(v.begin() + 1);  // Erases second element from array [{10, 20, 15}]
    }
    if(v.size() > 3)
    {
        // {10, 20, 13, 25, 45}
        v.erase(v.begin()+2, v.begin()+4);   // Erases element from third and fourth index 
        // {10, 20, 45} [start, end)
    }


    /*
    Insert function
    */
    
    vector<int> v_30(2, 30); // {30, 30}
    v_30.insert(v_30.begin(), 300); // {300, 30, 30}
    v_30.insert(v_30.begin()+1, 2, 35); // {300, 35, 35, 30, 30}

    vector<int> copy(2, 50);  // {50, 50}
    v_30.insert(v_30.begin(), copy.begin(), copy.end());   // {50, 50, 300, 35, 35, 30, 30}

    cout<<v.size()<<endl;  // Size of the vector
    v.pop_back();   // Delete last element

    v1.swap(v2); // swap vectors 
    v.clear(); // Erases the entire vector
    cout<<v.empty()<<endl;
}

void explain_list()
{
    list<int> lst;
    lst.push_back(2);  // {2}
    lst.emplace_back(4);  // {2, 4}
    lst.push_front(5);   // {5, 2, 4}
    lst.emplace_front(6);   // {6, 5, 2, 4}
    for(list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
    {
        cout<<*(it)<<" ";   // List can be printed through iterator only
    }
    cout<<endl;
    // Rest of the functions remain same as vectors
    // begin, end, rbegin, rend, clear, insert, size, swap
}

int main()
{
    cout<<"Vectors : "<<endl;
    explain_vectors();
    cout<<"List : "<<endl;
    explain_list();
    return 0;
}