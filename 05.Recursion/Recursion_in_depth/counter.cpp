#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_map>
using namespace std;

void counterFunc(int count)
{
    if(count == 3)
    {
        return;
    }    
    cout<<count<<" ";
    counterFunc(count+1);
}

int main()
{
    int count = 0;
    counterFunc(count);
    return 0;
}