#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    map<string, int> m;
    for (int i = 0; i < strs.size(); i++) {
      string word = strs[i];
      sort(word.begin(), word.end());
      if (m.find(word) == m.end()) {
        vector<string> v;
        v.push_back(strs[i]);
        result.push_back(v);
        m[word] = (int)result.size() - 1;

      } else {
        result[m[word]].push_back(strs[i]);
      }
    }

    return result;
  }
};

int main() {
  Solution s;
  vector<string> input_1{"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> result_1 = s.groupAnagrams(input_1);
  for (int i = 0; i < result_1.size(); ++i) {
    for (int j = 0; j < result_1[i].size(); ++j) {
      cout << result_1[i][j] << " ";
    }
    cout << endl;
  }
  // Output:
  // [
  //  ["ate","eat","tea"],
  //  ["nat","tan"],
  //  ["bat"]
  // ]

  return 0;
}
