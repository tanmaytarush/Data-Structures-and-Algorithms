/*

* MAP CONTAINER :-
  - A map is a data structure which stores every element in the form of a key and
    value pair.
  - Map always stores unique keys in sorted order.

*/

#include<iostream>
#include<map>
using namespace std;

void explainMap()
{
    map<int, int> mpp1;  // Key = integer and Value = integer
    map<int, pair<int, int>> mpp2;  // Key = integer and Value = pair
    map<pair<int, int>, int> mpp3;  // Key = pair and Value = integer

    mpp1[1] = 2;  // Key is 1 and Value is 2
    mpp2.emplace(3, std::make_pair(1, 0)); // No need to define the type
    mpp1.insert({2, 4}); // Need to define the type

    mpp3[{2,3}] = 10;

    // {
    //     {1,2},
    //     {2,4},
    //     {3,1}
    // }

    for(auto it : mpp1)
    {
        cout<<it.first<<" "<<it.second<<endl;  // Prints key with first and value with second
    }

    cout<<mpp1[1];
    cout<<mpp1[5];

    auto it3 = mpp1.find(3);
    cout<<it3->second; // Value at key 3

    auto it5 = mpp1.find(5);
    cout<<it5->second; // Value at key 5

    // Functions erase, swap, size, empty remains the same
}

void explainMultiMap()
{
    // Everything is the same as Map, just that it stores duplicate keys
}

void explainUnorderedMap()
{
    // Same difference as between Set and Unordered_Set
}

int main()
{
    cout<<"Map : "<<endl;
    explainMap();
    return 0;
}