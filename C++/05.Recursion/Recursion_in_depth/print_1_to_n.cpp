#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

static void print_1_to_n(int i, int n)
{
    if(i==0)
    {
        return;
    }
    //cout<<i<<" ";  // n to 1
    print_1_to_n(i-1, n);
    cout<<i<<" ";  // 1 to n
}


int main()
{
    int i=1;
    int n=5;
    print_1_to_n(n, n);
    return 0;
}
