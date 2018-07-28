#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) { solve(board); }

  bool solve(vector<vector<char>>& board) {
    int len = (int)board.size();
    for (int i = 0; i < len; ++i) {
      for (int j = 0; j < len; ++j) {
        if (board[i][j] == '.') {
          for (char c = '1'; c <= '9'; ++c) {
            if (isValid(board, i, j, c) == true) {
              board[i][j] = c;
              if (solve(board) == true) {
                return true;
              } else {
                board[i][j] = '.';
              }
            }
          }
          return false;
        }
      }
    }
    return true;
  }

  bool isValid(vector<vector<char>>& board, int col, int row, char c) {
    for (int i = 0; i < board.size(); ++i) {
      if (board[col][i] != '.' && board[col][i] == c) {
        return false;
      }
      if (board[i][row] != '.' && board[i][row] == c) {
        return false;
      }

      char cube_c = board[3 * (col / 3) + i % 3][3 * (row / 3) + i / 3];
      if (cube_c != '.' && cube_c == c) {
        return false;
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
  s.solveSudoku(input_1);
  for (int i = 0; i < input_1.size(); ++i) {
    for (int j = 0; j < input_1[0].size(); ++j) {
      cout << input_1[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
