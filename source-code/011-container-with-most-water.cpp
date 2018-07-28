#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    if (height.size() <= 0) {
      return 0;
    }
    int l = 0;
    int r = (int)height.size() - 1;
    int max_area = 0;

    while (l < r) {
      max_area = max(max_area, min(height[l], height[r]) * (r - l));
      if (height[l] < height[r]) {
        ++l;
      } else {
        --r;
      }
    }
    return max_area;
  }
};

int main() {
  Solution s;
  vector<int> height{1, 4, 6, 3, 7, 6, 3};  // Output: 18
  cout << s.maxArea(height) << endl;
  return 0;
}
