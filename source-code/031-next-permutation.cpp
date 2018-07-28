#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    if (nums.size() == 0) {
      return;
    }
    int len = (int)nums.size();

    // 找到最右邊的一個數i, nums[i] < nums[i+1]
    int first_num = -1;
    for (int i = len - 2; i >= 0; --i) {
      if (nums[i] < nums[i + 1]) {
        first_num = i;
        break;
      }
    }

    if (first_num == -1) {
      reverse(nums.begin(), nums.end());
      return;
    }

    // 找到最右邊的一個數i, nums[first_num] < nums[second_num]
    int second_num = first_num + 1;
    for (int i = len - 1; i > first_num; --i) {
      if (nums[first_num] < nums[i]) {
        second_num = i;
        break;
      }
    }
    int temp = nums[first_num];
    nums[first_num] = nums[second_num];
    nums[second_num] = temp;
    reverse(nums.begin() + first_num + 1, nums.end());
    return;
  }
};

int main() {
  // 返回一個數，緊挨著大於輸入的數
  // 如果輸入的數是最大數，就回傳最小的數
  Solution s;

  vector<int> input_1{1, 2, 3};
  s.nextPermutation(input_1);
  for (int i = 0; i < input_1.size(); ++i) {
    cout << input_1[i] << " ";
  }
  cout << endl;
  // Output: [1,3,2]

  vector<int> input_2{3, 2, 1};
  s.nextPermutation(input_2);
  for (int i = 0; i < input_2.size(); ++i) {
    cout << input_2[i] << " ";
  }
  cout << endl;
  // Output: [1,2,3]

  vector<int> input_3{1, 1, 5};
  s.nextPermutation(input_3);
  for (int i = 0; i < input_3.size(); ++i) {
    cout << input_3[i] << " ";
  }
  cout << endl;
  // Output: [1,5,1]

  vector<int> input_4{2, 3, 1, 3, 3};
  s.nextPermutation(input_4);
  for (int i = 0; i < input_4.size(); ++i) {
    cout << input_4[i] << " ";
  }
  cout << endl;
  // Output: [2,3,3,1,3]

  vector<int> input_5{2, 3, 1};
  s.nextPermutation(input_5);
  for (int i = 0; i < input_5.size(); ++i) {
    cout << input_5[i] << " ";
  }
  cout << endl;
  // Output: [3,1,2]

  return 0;
}
