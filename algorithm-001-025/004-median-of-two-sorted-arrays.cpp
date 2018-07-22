#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <limits.h>

using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int nums1_len = (int)nums1.size();
    const int nums2_len = (int)nums2.size();
    // 讓因為是在nums1二分搜尋，選小的讓搜索速度快一點
    if (nums1_len > nums2_len) {
      return findMedianSortedArrays(nums2, nums1);
    }
    // 當兩個數列個數的和是奇數時，中位數的index是(k-1)
    // 當和是偶數時，兩個中位數的index分別是(k-1)和k
    const int k = (nums1_len + nums2_len + 1) / 2;
    int l = 0;
    int r = nums1_len;

    while (l < r) {
      // m1和m2是中位數k的候選人
      const int m1 = (r + l) / 2;
      const int m2 = k - m1;
      if (nums1[m1] < nums2[m2 - 1]) {
        l = m1 + 1;
      } else {
        r = m1;
      }
    }

    const int m1 = l;
    const int m2 = k - m1;
    int c1 = std::max(m1 <= 0 ? INT_MIN : nums1[m1 - 1],
                      m2 <= 0 ? INT_MIN : nums2[m2 - 1]);
    if ((nums1_len + nums2_len) % 2 == 1) {
      return c1;
    }
    int c2 = std::min(m1 >= nums1_len ? INT_MAX : nums1[m1],
                      m2 >= nums2_len ? INT_MAX : nums2[m2]);
    return (double)(c1 + c2) / 2;
  }
};

int main() {
  Solution s;
  vector<int> nums1{1, 2, 3, 3};
  vector<int> nums2{4, 5, 6, 7};
  cout << s.findMedianSortedArrays(nums1, nums2) << endl;
  return 0;
}
