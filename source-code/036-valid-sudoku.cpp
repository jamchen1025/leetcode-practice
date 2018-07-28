#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    const int len = 9;
    bool row[len][len] = {false};
    bool col[len][len] = {false};
    bool cube[len][len] = {false};

    for (int i = 0; i < len; ++i) {
      for (int j = 0; j < len; ++j) {
        if (board[i][j] == '.') {
          continue;
        }
        int v = board[i][j] - '0' - 1;

        if (col[i][v] == true) {
          return false;
        } else {
          col[i][v] = true;
        }

        if (row[j][v] == true) {
          return false;
        } else {
          row[j][v] = true;
        }

        int cube_i = i / 3;
        int cube_j = j / 3;
        int cube_idx = cube_i + cube_j * 3;
        if (cube[cube_idx][v] == true) {
          return false;
        } else {
          cube[cube_idx][v] = true;
        }
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  vector<vector<char>> input_1{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                               {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                               {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                               {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                               {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                               {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                               {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                               {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                               {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  cout << s.isValidSudoku(input_1) << endl;  // Output: 1

  input_1[0][0] = '8';
  cout << s.isValidSudoku(input_1) << endl;  // Output: 0

  return 0;
}
