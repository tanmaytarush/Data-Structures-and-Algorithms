#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<algorithm>
using namespace std;

static void printNTimes(int i, int n)
{
    if(i>n)
    {
        return;
    }
    cout<<"tanmay"<<endl;
    printNTimes(i+1, n);
}

int main()
{
    int i = 1;
    int n = 5;
    printNTimes(i, n);
    return 0;
}