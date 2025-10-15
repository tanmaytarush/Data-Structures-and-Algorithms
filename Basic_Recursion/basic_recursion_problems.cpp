/*

** BASIC RECURSION PROBLEMS :-

    - Print name N times
    - Print linearly from 1 to N
    - Print from N to 1
    - Print linearly from 1 to N (Backtracking)
    - Print from N to 1 (Backtracking)

*/

#include<iostream>
using namespace std;

class basicRecursionProblems{
public:
    void print_name_n_times_1(int n)
    {
            if(n==0) return;
            cout<<"ABC"<<endl;
            print_name_n_times_1(n-1);
    }

    void print_1toN(int i, int n)
    {
        if(i>n)
            return;
        cout<<i<<" ";
        print_1toN(i+1, n);
    }

    void print_Nto1(int i, int n) 
    {
        if(i<1)
            return;
        cout<<i<<" ";
        print_Nto1(i-1, n);
    }

    void print_1toN_backtracking(int i, int n) // Print after stack returns
    {
        if(i<1)
            return;
        print_1toN_backtracking(i-1, n);
        cout<<i<<" ";
    }

    void print_Nto1_backtracking(int i, int n) // Prints after stack returns
    {
        if(i>n)
            return;
        print_Nto1_backtracking(i+1, n);
        cout<<i<<" ";
    }
};

int main()
{
    basicRecursionProblems x;
    int n;
    cin>>n;
    x.print_name_n_times_1(n);
    x.print_1toN(1,n);
    x.print_Nto1(n,n);
    x.print_1toN_backtracking(n,n);
    x.print_Nto1_backtracking(1,n);
}