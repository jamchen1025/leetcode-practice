/**********************************************************************************
題目：
https://leetcode.com/problems/median-of-two-sorted-arrays/
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.
Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
**********************************************************************************
想法：
先求出合併數列後中位數的位置k
  (nums1.size() + num2.size() + 1) / 2
  記得+1,這樣k也代表合併數列0~(k-1)的個數
若合併數列長度是偶數則回傳: (n[k - 1] + n[k]) /2，反之回傳n[k - 1]
預先知識:
  兩個數列分別有兩個候選人:
    nums1[m1 - 1]: nums1 中 n[k - 1]的候選人，盡量大
    nums1[m1]:     nums1 中 n[k]    的候選人，盡量小
    nums1[m1 - 1] < nums1[m1]

    nums2[m2 - 1]: nums2 中 n[k - 1]的候選人，盡量大
    nums2[m2]:     nums2 中 n[k]    的候選人，盡量小
    nums2[m2 - 1]] < nums2[m2
  m1跟k和m2的關係
    nums1中0~(m1-1)的個數和nums2中0~(m2-1)的個數和會等於k
  m1的選擇
    nums1[m1] 要大於 nums2[m2 - 1] 否則 nums1[m1]就會變成 n[k - 1]的候選人
    nums1[m1] 要盡量小才能逼近成為n[k]的候選人
 然後用二分搜尋求m1
**********************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <limits.h>

using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int nums1_len = (int)nums1.size();
    int nums2_len = (int)nums2.size();

    if (nums1_len > nums2_len) {
      return findMedianSortedArrays(nums2, nums1);
    }
    int k = (nums1_len + nums2_len + 1) / 2;

    // 利用變形的二分搜尋法，移動l的位置當作m1的位置
    int l = 0;
    int r = nums1_len;
    while (l < r) {
      int m1 = l + (r - l) / 2;
      int m2 = k - m1;
      if (nums1[m1] < nums2[m2 - 1]) {
        l = m1 + 1;  // 此時m1不可能是m1候選，直接把l移動到 m + 1避免下次選到
      } else {
        r = m1;
      }
    }

    int m1 = l;
    int m2 = k - m1;
    int min_m = max((m1 - 1 < 0) ? INT_MIN : nums1[m1 - 1],
                    (m2 - 1 < 0) ? INT_MIN : nums2[m2 - 1]);
    if ((nums1_len + nums2_len) % 2 == 1) {
      return min_m;
    }
    int max_m = min((m1 >= nums1_len) ? INT_MAX : nums1[m1],
                    (m2 >= nums2_len) ? INT_MAX : nums2[m2]);

    return (double)(min_m + max_m) / 2;
  }
};

int main() {
  Solution s;
  vector<int> nums1{1, 2, 3, 3};
  vector<int> nums2{4, 5, 6, 7};
  cout << s.findMedianSortedArrays(nums1, nums2) << endl;
  return 0;
}
