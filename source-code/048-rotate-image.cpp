#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int len = (int)matrix.size();
    if (len <= 1) {
      return;
    }
    int max_idx = len - 1;
    for (int i = 0; i < len / 2; ++i) {
      int low = i, high = max_idx - i;
      for (int j = low; j < high; ++j) {
        int temp = matrix[i][j];
        // left to top
        matrix[i][j] = matrix[max_idx - j][i];
        // bottom to left
        matrix[max_idx - j][i] = matrix[max_idx - i][max_idx - j];
        // right to bottom
        matrix[max_idx - i][max_idx - j] = matrix[j][max_idx - i];
        // top to right
        matrix[j][max_idx - i] = temp;
      }
    }
    return;
  }
};

int main() {
  Solution s;
  vector<vector<int>> input_1{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  s.rotate(input_1);
  for (int i = 0; i < input_1.size(); ++i) {
    for (int j = 0; j < input_1[i].size(); ++j) {
      cout << input_1[i][j] << " ";
    }
    cout << endl;
  }
  // Output:
  // [
  //  [7,4,1],
  //  [8,5,2],
  //  [9,6,3]
  // ]

  cout << "------------------" << endl;
  vector<vector<int>> input_2{
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  s.rotate(input_2);
  for (int i = 0; i < input_2.size(); ++i) {
    for (int j = 0; j < input_2[i].size(); ++j) {
      cout << input_2[i][j] << " ";
    }
    cout << endl;
  }
  // Output:
  // [
  //  [15,13, 2, 5],
  //  [14, 3, 4, 1],
  //  [12, 6, 8, 9],
  //  [16, 7,10,11]
  // ]
  return 0;
}
