/**********************************************************************************
題目：
https://leetcode.com/problems/spiral-matrix/description/
Given a matrix of m x n elements (m rows, n columns), 
return all elements of the matrix in spiral order.
Example 1:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
**********************************************************************************
想法：
**********************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.size() == 0 || matrix[0].size() == 0) {
      return result;
    }

    int row_s = 0;
    int row_e = (int)matrix.size() - 1;
    int col_s = 0;
    int col_e = (int)matrix[0].size() - 1;
    while (row_s <= row_e && col_s <= col_e) {
      for (int i = col_s; i <= col_e; ++i) {
        result.push_back(matrix[row_s][i]);
      }
      ++row_s;
      for (int i = row_s; i <= row_e; ++i) {
        result.push_back(matrix[i][col_e]);
      }
      --col_e;
      if (row_s <= row_e) {
        for (int i = col_e; i >= col_s; --i) {
          result.push_back(matrix[row_e][i]);
        }
        --row_e;
      }
      if (col_s <= col_e) {
        for (int i = row_e; i >= row_s; --i) {
          result.push_back(matrix[i][col_s]);
        }
        ++col_s;
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<vector<int>> input_1{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> result_1 = s.spiralOrder(input_1);
  for (int i = 0; i < result_1.size(); ++i) {
    cout << result_1[i] << " ";
  }
  cout << endl;
  // Output: [1,2,3,6,9,8,7,4,5]

  vector<vector<int>> input_2{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  vector<int> result_2 = s.spiralOrder(input_2);
  for (int i = 0; i < result_2.size(); ++i) {
    cout << result_2[i] << " ";
  }
  cout << endl;
  // Output: [1,2,3,4,8,12,11,10,9,5,6,7]

  vector<vector<int>> input_3{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};

  vector<int> result_3 = s.spiralOrder(input_3);
  for (int i = 0; i < result_3.size(); ++i) {
    cout << result_3[i] << " ";
  }
  cout << endl;
  // Output: [1,2,3,4,5,6,7,8,9,10]
  return 0;
}
