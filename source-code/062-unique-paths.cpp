/********************************************************************************** 
題目：
https://leetcode.com/problems/unique-paths/description/
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
Above is a 7 x 3 grid. How many possible unique paths are there?
Note: m and n will be at most 100.
Example 1:
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:
Input: m = 7, n = 3
Output: 28
**********************************************************************************
想法：
**********************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp;
    for (int i = 0; i < m; ++i) {
      vector<int> temp;
      for (int j = 0; j < n; ++j) {
        temp.push_back(1);
      }
      dp.push_back(temp);
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m - 1][n - 1];
  }
  int uniquePaths2(int m, int n) {
    int total = m + n - 2;
    int m1 = m - 1;
    double result = 1;
    for (int i = 1; i <= m1; ++i) {
      result = result * (total - m1 + i) / i;
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << s.uniquePaths(7, 3) << endl;   // Output: 28
  cout << s.uniquePaths2(3, 2) << endl;  // Output: 3
  return 0;
}

