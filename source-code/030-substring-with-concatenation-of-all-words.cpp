#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    if (s.size() == 0 || words.size() == 0) {
      return result;
    }
    int s_len = (int)s.size();
    int words_len = (int)words.size();
    map<string, int> words_map;
    for (int i = 0; i < words_len; ++i) {
      if (words_map.find(words[i]) != words_map.end()) {
        words_map[words[i]]++;
      } else {
        words_map[words[i]] = 1;
      }
    }
    int word_len = (int)words[0].size();

    for (int i = 0; i < s_len - (word_len * words_len - 1); ++i) {
      map<string, int> temp = words_map;
      int count = words_len;
      int index = i;

      while (true) {
        string sub_str = s.substr(index, word_len);
        if (temp.find(sub_str) != temp.end()) {
          if (temp[sub_str] > 0) {
            temp[sub_str]--;
            index += word_len;
            --count;
          }
          if (temp[sub_str] == 0) {
            temp.erase(sub_str);
          }
        } else {
          break;
        }
      }
      if (count == 0) {
        result.push_back(i);
      }
    }

    return result;
  }
};

int main() {
  Solution s;
  vector<string> input_1{"foo", "bar"};
  vector<int> result = s.findSubstring("barfoothefoobarman", input_1);
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i] << " ";
  }
  cout << endl;
  // Output: [0,9]
  // Explanation: Substrings starting at index 0 and 9 are "barfoor" and
  // "foobar" respectively.
  // The output order does not matter, returning [9,0] is fine too.

  vector<string> input_2{"word", "student"};
  result = s.findSubstring("wordgoodstudentgoodword", input_2);
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i] << " ";
  }
  cout << endl;
  // Output: []

  return 0;
}
