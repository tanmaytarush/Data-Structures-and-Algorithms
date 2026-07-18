/*
ABC 467 - Alternate Sums

Problem Statement
You are given integer sequences:
  A = (A_1, A_2, ..., A_N)
  B = (B_1, B_2, ..., B_{N-1})

Each A_i and B_i is an integer between 0 and M-1, inclusive.
The length of A is N, and the length of B is N-1.

You may perform the following operation on A any number of times:
  - Choose an integer i with 1 <= i <= N, and add 1 to A_i.

Find the minimum number of operations required so that:
  (A_i + A_{i+1}) mod M = B_i
for every i = 1, 2, ..., N-1.

It is guaranteed that the condition can always be satisfied.

Constraints
  - 2 <= N <= 2 * 10^5
  - M = 2
  - 0 <= A_i <= M - 1
  - 0 <= B_i <= M - 1
  - All input values are integers

Input
  N M
  A_1 A_2 ... A_N
  B_1 B_2 ... B_{N-1}

Output
  Print the minimum number of operations on one line.

Sample Input 1
  3 2
  1 1 1
  1 1

Sample Output 1
  1

Sample Input 2
  2 2
  1 1
  0

Sample Output 2
  0

Sample Input 3
  10 2
  0 0 0 1 1 0 1 0 1 0
  0 1 0 1 0 1 0 1 0

Sample Output 3
  4
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(N - 1);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] %= 2;
    }

    for (int i = 0; i < N - 1; i++)
        cin >> B[i];

    int answer = 1e9;

    // Try both possibilities for the first parity
    for (int start = 0; start <= 1; start++) {

        vector<int> parity(N);
        parity[0] = start;

        // Construct the only possible parity sequence
        for (int i = 0; i < N - 1; i++) {
            parity[i + 1] = parity[i] ^ B[i];
        }

        int cost = 0;

        for (int i = 0; i < N; i++) {
            if (parity[i] != A[i])
                cost++;
        }

        answer = min(answer, cost);
    }

    cout << answer << "\n";

    return 0;
}
