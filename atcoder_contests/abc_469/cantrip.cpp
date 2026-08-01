/*

Problem Statement
You are given a string 
S of length 
N consisting of o and x.
N bags are arranged in a row, and each bag contains one sweet.
On the 
i-th bag, "hit" is written if the 
i-th character of 
S is o, and "miss" is written if it is x.
For each 
k=1,2,…,N, solve the following problem.

Takahashi receives the first 
k bags from the front of the row, eats the sweets inside them, and keeps the bags.
Then, he repeats the following action as many times as possible.

He discards one bag marked "hit" that he is holding, receives the bag at the front of the row, eats the sweet inside it, and keeps that bag. This action can only be performed when there is still a bag remaining in the row and he is holding a bag marked "hit".
Find the number of sweets he can eat.
Note that when he receives a bag, that bag is removed from the row.

*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    int N;
    cin>>S>>N;

    vector<int> prefO(N-1, 0);
    vector<int> xPos;

    // store positions of 'x' and 'o'
    for(int i=0; i<N; i++)
    {
        prefO[i+1] = prefO[i] + (S[i]=='o');
        if(S[i] == 'x')
        {
            xPos.push_back(i+1);
        }
    }

    // for later indexes
    for(int k=1; k<=N; k++)
    {
        int hits = prefO[k];

        if(hits == 0)
        {
            cout<<k<<endl;
        }

        else
        {
            int idx = upper_bound(xPos.begin(), xPos.end(), k) - xPos.begin();

            int target = idx + hits - 1;

            if(target<(int)xPos.size())
            {
                cout<<xPos[target];
            }
            else
            {
                cout<<N<<endl;
            }
        }
        cout << (k == N ? '\n' : ' ');
    }

    return 0;
}