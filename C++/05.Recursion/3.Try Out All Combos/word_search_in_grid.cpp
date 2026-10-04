/*QUESTION:
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false


Approach:
We can use a backtracking approach to solve this problem.
1. Create a helper function called 'solve' that takes the current row index, column index, letter index, the target word, and the board.
2. In the 'solve' function:
   - If the letter index is equal to the length of the target word, set the flag to true and return.
   - Check if the current cell value is equal to the target letter.
   - If it is, mark the current cell as visited (by changing its value to '!') and recursively call the 'solve' function for its neighboring cells (up, down, left, and right).
   - After the recursive call, restore the original value of the current cell.
3. Create the main function called 'exist' that calculates and returns true if the word exists in the grid, false otherwise.
   - Initialize a flag variable to false.
   - Iterate through each cell in the grid.
   - If the current cell value is equal to the first letter of the target word, mark the current cell as visited (by changing its value to '!') and call the 'solve' function with the current cell's coordinates, letter index as 1, the target word, and the board.
   - If the flag is true, return true (word exists in the grid).
   - If the loop completes without finding the word, return false.
   
Time Complexity: O(M * N * 4^L), where M is the number of rows, N is the number of columns in the grid, and L is the length of the target word. In the worst case, we traverse the entire grid for each letter in the target word, and we have 4 choices (up, down, left, right) at each step.
Space Complexity: O(L), where L is the length of the target word. The space is used for the recursive call stack.

CODE:*/

// Note:- I'm making recursive call only for the potential grids rather than making call for the all four to reduce unwanted calls,
// this makes code quite big but if you want to make it compact you could make call for all four cases and after call check if it's valid
// just check the code of rat in maze for shorter code

#define LOG(x) cerr<<#x<<" "<<x<<endl;

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution
{
    private:
        bool dfs(vector<vector<char>> &board, string word, int i, int j, int idx)
        {
            if(idx == word.size())
            {
                return true;
            }

            if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] != word[idx])
            {
                return false;
            }

            char temp = board[i][j];
            board[i][j] = '#';

            bool found = dfs(board, word, i+1, j, idx+1) ||
                        dfs(board, word, i-1, j, idx+1) ||
                        dfs(board, word, i, j+1, idx+1) ||
                        dfs(board, word, i, j-1, idx+1);

            board[i][j] = temp;

            return found;
        }

    public:
        bool exist(vector<vector<char>> &board, string word)
        {
            int rows = board.size();
            int cols = board[0].size();

            for(int i=0; i<rows; ++i)
            {
                for(int j=0; j<cols; ++j)
                {
                    if(dfs(board, word, i, j, 0))
                    {
                        return true;
                    }
                }
            }
            return false;
        }
};

int main()
{
    Solution sol;

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    cout << boolalpha << sol.exist(board, "ABCCED") << endl; // true
    cout << boolalpha << sol.exist(board, "SEE") << endl;    // true
    cout << boolalpha << sol.exist(board, "ABCB") << endl;   // false
}