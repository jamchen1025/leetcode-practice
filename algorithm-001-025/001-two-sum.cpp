#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> r;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      std::unordered_map<int, int>::iterator it = map.find(target - nums.at(i));
      if (it != map.end()) {
        r.push_back(it->second);
        r.push_back(i);
        return r;
      }
      map[nums.at(i)] = i;
    }
    return r;
  }
};

int main() {
  vector<int> inputs{2, 7, 11, 15};
  Solution s;
  vector<int> r = s.twoSum(inputs, 9);
  for (int i = 0; i < r.size(); ++i) cout << r.at(i) << " ";
  cout << "\n";
  return 0;
}
