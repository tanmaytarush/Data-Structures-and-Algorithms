// Convert a binary number to a decimal one

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

int binaryToDec(string nums)
{
    int n = nums.length();
    int p = 1;
    int dec = 0;
    for(int i=n-1; i>=0; --i)
    {
        if(nums[i] == '1')
        {
            dec += p;
        }
        p = p*2;
    }

    return dec;
}

int main()
{
    string nums;
    getline(cin, nums);

    int decimal = binaryToDec(nums);

    cout<<decimal;

    return 0;
}