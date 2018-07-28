#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    if (candidates.size() == 0) {
      return result;
    }
    sort(candidates.begin(), candidates.end());
    vector<int> list;
    backTracking(result, list, candidates, target, 0);

    return result;
  }

  void backTracking(vector<vector<int>>& result, vector<int> list,
                    vector<int> candidates, int target, int start) {
    if (target < 0) {
      return;
    }
    if (target == 0) {
      result.push_back(list);
      return;
    }

    for (int i = start; i < candidates.size(); ++i) {
      if (target - candidates[i] < 0) {
        break;
      }
      if (i > start && candidates[i] == candidates[i - 1]) {
        continue;
      }

      list.push_back(candidates[i]);
      backTracking(result, list, candidates, target - candidates[i], i + 1);
      list.pop_back();
    }
  }
};

int main() {
  Solution s;
  vector<int> input_1{10, 1, 2, 7, 6, 1, 5};
  vector<vector<int>> result_1 = s.combinationSum2(input_1, 8);
  for (int i = 0; i < result_1.size(); ++i) {
    for (int j = 0; j < result_1[i].size(); ++j) {
      cout << result_1[i][j] << " ";
    }
    cout << endl;
  }
  // Output:
  // [
  //  [1, 7],
  //  [1, 2, 5],
  //  [2, 6],
  //  [1, 1, 6]
  // ]

  cout << "---------------" << endl;

  vector<int> input_2{2, 5, 2, 1, 2};
  vector<vector<int>> result_2 = s.combinationSum2(input_2, 5);
  for (int i = 0; i < result_2.size(); ++i) {
    for (int j = 0; j < result_2[i].size(); ++j) {
      cout << result_2[i][j] << " ";
    }
    cout << endl;
  }
  // Output:
  // [
  //  [1,2,2],
  //  [5]
  // ]

  return 0;
}
