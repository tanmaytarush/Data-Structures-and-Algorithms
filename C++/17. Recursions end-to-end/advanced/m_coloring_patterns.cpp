/*

M - Coloring Problem


1

Problem Statement: Given an undirected graph and a number m, determine if the graph can be colored with at most m colors such that no two adjacent vertices of the graph are colored with the same color.

Examples
Example 1:
Input:
  
N = 4  
M = 3  
E = 5  
Edges[] = {  
  (0, 1),  
  (1, 2),  
  (2, 3),  
  (3, 0),  
  (0, 2)  
}  
Output:
 1  
Explanation:
  
It is possible to color the given graph using 3 colors, so the answer is 1 (possible).

Example 2:
Input:
  
N = 3  
M = 2  
E = 3  
Edges[] = {  
  (0, 1),  
  (1, 2),  
  (0, 2)  
}  
Output:
 0  
Explanation:
  
It is not possible to color the graph using 2 colors as it forms a triangle, which requires at least 3 colors. Hence, the answer is 0 (not possible).

*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
};

int main()
{

}