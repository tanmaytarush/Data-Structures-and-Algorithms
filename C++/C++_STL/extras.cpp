/*

* IMPORTANT ALGORITHMS THROUGH STL :-

*/

#include<iostream>
#include<vector>
using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    // when they are same
    if(p1.first > p2.first) return true;
    return false;
}

void explainExtras()
{
    int n = 5;
    int arr[] = {4, 3, 6, 2, 7};
    vector<int> v;
    sort(arr, arr+n);
    sort(v.begin(), v.end());
    sort(arr+2, arr+4);
    sort(arr, arr+n, greater<int>()); // Comparator sorts in descending order

    pair<int, int> a[] = {{1,2}, {2,1}, {4,1}};

    /*
    Custom Sorting:
    Sort it according to the second element, if second element is same,
    then sort it according to first element but in descending.
    */

    sort(a, a+n, comp);

    // Extra Functions
    int num1 = 7;
    int cnt1 = __builtin_popcount(num1); 
    cout<<cnt1<<endl;  // Number of 1's in bit conversion

    long long num2 = 144526345427;
    int cnt2 = __builtin_popcountll(num2);
    cout<<cnt2<<endl;  // Number of 1's in bit conversion

    string s = "123";
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(), s.end())); // All permutations one-by-one

    int maxi = *max_element(arr, arr+n); // Returns the maximum element via dereference
}

int main()
{
    cout<<"Results : "<<endl;
    explainExtras();
    return 0;
}