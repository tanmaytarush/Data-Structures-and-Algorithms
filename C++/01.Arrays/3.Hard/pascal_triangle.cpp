/*
**Question:**

Given an integer `rowIndex`, return the `rowIndex`th (0-indexed) row of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: `rowIndex = 3`

Output: `[1, 3, 3, 1]`
*/

/*
**APPROACH:**

Algorithm 1 :-
To generate the entire Pascal’s Triangle for the first N rows, we can start with the first row containing a single 1 
and iteratively build each subsequent row using the property that every element (except the first and last) is the sum 
of the two elements directly above it from the previous row. The first and last elements of each row are always 1. 
By storing the previous row, we can calculate the next row easily. This process continues until we have constructed all N rows, 
resulting in the complete Pascal’s Triangle structure.

Algorithm 2:-
To print the Nth row of the pascal triangle we can take advantage of the relationship between Nth element and binomial coefficients.
In a pascal's triangle, the Nth row contains the binomial coefficients C(N-1, 0), C(N-1, 1) and so on till C(N-1, N-1). 
Thus we can simply calculate all these values to return the Nth row of pascal triangle.
Instead of computing full factorials, we can start with the first value as 1, and use the relation C(n, k) = C(n, k−1) × (n−k+1) / k 
to compute the next value from the previous one in constant time.

Algorithm 3:-
To find the element at the coordinates (R,C) where R is the row number and C is the Column number, 
we can simply simulate the generation of pascal's triangle for R rows. In Pascal’s Triangle, 
the element at row R and column C corresponds to the binomial coefficient (r-1)C(c-1). 
To calculate this binomial coefficient, we can simply apply the formula of binomial coefficient i.e. (r-1)!/(c-1)!(r-c)!.
Instead of computing full factorials (which can overflow and be slow), we can multiply and divide in a 
loop to compute the coefficient efficiently.



**CODE:**
*/
#include<iostream>
using namespace std;
#include<vector>

class PascalTriangle
{
  public:
  // Complete pascal triangle printing
  vector<vector<int>> PascalTriangleBF(int numRows)
  {
    vector<vector<int>> triangle;
    for(int i=0; i<numRows; ++i)
    {
      vector<int> row(i+1, 1);
      for(int j=1; j<i; ++j)
      {
        row[j] = triangle[i-1][j-1] + triangle[i-1][j];
      }
      triangle.push_back(row);
    }
    return triangle;
  }

  // Better approach for Pascal's Triangle for getting Nth row
  vector<int> PascalTriangleBetter(int N)
  {
    vector<int> row;
    long long ans = 1;
    row.push_back(ans);
    for(int i=1; i<=N; ++i)
    {
      ans = ans * (N-i);
      ans = ans / i;
      row.push_back(ans);
    }
    return row;
  }

  // Generate Rows
  vector<int> generateRows(int N)
  {
    vector<int> row;
    long long ans = 1;
    row.push_back(ans);
    for(int i=1; i<=N; ++i)
    {
      ans = ans * (N-i+1);
      ans = ans / i;
      row.push_back(ans);
    }
    return row;
  }

  // To find the element at a particular position inside Pascal's Triangle
  vector<vector<int>> PascalTriangleOptimal(int N)
  {
    vector<vector<int>> triangle;
    for(int i=0; i<N; ++i)
    {
      vector<int> row = generateRows(i);
      triangle.push_back(row);
    }
    return triangle;
  }
};

int main()
{
  int n;
  cin>>n;

  PascalTriangle p;

  vector<vector<int>> result1 = p.PascalTriangleBF(n);
  vector<int> result2 = p.PascalTriangleBetter(n);
  vector<vector<int>> result3 = p.PascalTriangleOptimal(n);

  for(vector<vector<int>>::iterator it = result1.begin(); it != result1.end(); ++it)
  {
    for(vector<int>::iterator jt = it->begin(); jt != it->end(); ++jt)
    {
      cout<<*jt<<" ";
    }
    cout<<endl;
  }

  cout<<endl;

  for(vector<vector<int>>::iterator it = result3.begin(); it != result3.end(); ++it)
  {
    for(vector<int>::iterator jt = it->begin(); jt != it->end(); ++jt)
    {
      cout<<*jt<<" ";
    }
    cout<<endl;
  }
}

/*
**COMPLEXITY ANALYSIS:**
- Time Complexity: O(rowIndex)
  - We iterate over each element in the row and calculate its value using the binomial coefficient formula.
- Space Complexity: O(rowIndex)
  - We use additional space to store the row of Pascal's triangle.

Overall, the algorithm has a linear time complexity and linear space complexity.
*/
