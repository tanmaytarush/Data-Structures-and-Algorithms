// Convert a decimal number to binary

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string decimalToBin(int n)
{
    string num = "";
    int rem = 0;
    while(n>0)
    {
        rem = n%2;
        num += to_string(rem); // integer to char conversion
        n = n/2;
    }
    reverse(num.begin(), num.end());

    return num;
}

int main()
{
    int n;
    cin>>n;

    string result = decimalToBin(n);

    for(char it : result)
    {
        cout<<it;
    }

    return 0;
}