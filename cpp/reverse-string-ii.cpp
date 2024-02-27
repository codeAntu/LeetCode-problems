#include <algorithm>
#include <string>
class Solution {
public:
  std::string reverseStr(std::string s, int k) {
    int n = s.size();
    for (int i = 0; i < n; i += 2 * k) {
      int j = std::min(i + k, n);
      std::reverse(s.begin() + i, s.begin() + j);
    }
    return s;
  }
};
