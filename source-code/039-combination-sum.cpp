#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
      list.push_back(candidates[i]);
      backTracking(result, list, candidates, target - candidates[i], i);
      list.pop_back();
    }
  }
};

int main() {
  Solution s;
  vector<int> input_1{2, 3, 6, 7};
  vector<vector<int>> result_1 = s.combinationSum(input_1, 7);
  for (int i = 0; i < result_1.size(); ++i) {
    for (int j = 0; j < result_1[i].size(); ++j) {
      cout << result_1[i][j] << " ";
    }
    cout << endl;
  }
  // Output:
  // [
  //  [7],
  //  [2,2,3]
  // ]

  cout << "---------------" << endl;

  vector<int> input_2{2, 3, 5};
  vector<vector<int>> result_2 = s.combinationSum(input_2, 8);
  for (int i = 0; i < result_2.size(); ++i) {
    for (int j = 0; j < result_2[i].size(); ++j) {
      cout << result_2[i][j] << " ";
    }
    cout << endl;
  }
  // Output:
  // [
  //  [2,2,2,2],
  //  [2,3,3],
  //  [3,5]
  // ]

  return 0;
}
