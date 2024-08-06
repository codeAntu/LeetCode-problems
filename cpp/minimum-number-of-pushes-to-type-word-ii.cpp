#include <algorithm>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int minimumPushes(string word) {
    vector<int> chars(26, 0);

    for (int i = 0; i < word.length(); i++) {
      chars[word[i] - 'a']++;
    }

    sort(chars.begin(), chars.end(), greater<int>());

    int ans = 0;
    for (int i = 0; i < 26; i++) {
      if (chars[i] == 0) {
        break;
      }
      ans += chars[i] * (i / 8 + 1);
    }
    return ans;
  }
};

int main() {
  Solution s;

  return 0;
}