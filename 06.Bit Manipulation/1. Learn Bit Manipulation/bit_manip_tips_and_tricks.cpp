/*
Bit Manipulation Tricks and Techniques
1. Swapping Two Numbers Without a Third Variable
A = A ^ B
B = A ^ B
A = A ^ B
2. Checking if the i-th Bit is Set
(1 << i) & num   → set if result ≠ 0
(num >> i) & 1   → set if result ≠ 0
3. Setting the i-th Bit
num | (1 << i)
4. Clearing the i-th Bit
num & ~(1 << i)
5. Toggling the i-th Bit
num ^ (1 << i)
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

void swap2Numbers(int a, int b)
{
    a = a ^ b;
    b = a ^ b; // a^b^b = a
    a = a ^ b; // a^b^a = b

    cout<<a<<" "<<b<<endl;
}

void ithBitSet(int num, int i)
{
    if((num & (1 << i)) != 0)
    {
        cout<<true;
    }
    else
    {
        cout<<false;
    }

    /*
    if(i & (num >> i) != 0)
    {
        return true;
    }
    return false;
    */
}

void setithBit(int num, int i) // 0 to 1 or 1 to 1
{
    int ans = num | (1 << i);
    cout<<ans<<endl;
}

void clearithBit(int num, int i) // 1 to 0 or 0 to 0
{
    int ans = num & ~(1 << i);
    cout<<ans<<endl;
}

void toggleithBit(int num, int i)
{
    int ans = num ^ (1 << i);
    cout<<ans;
}

int main()
{
    int num, i;
    cin>>num>>i;

    swap2Numbers(5, 3);
    ithBitSet(num, i);
    setithBit(num, i);
    clearithBit(num, i);
    toggleithBit(num, i);

    return 0;
}