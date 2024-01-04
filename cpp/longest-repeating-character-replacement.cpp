
#include "math.h"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    int ans = 0;
    int left = 0, right = 0;
    vector<int> vec = vector<int>(26, 0);

    int maxFre = 0;

    for (right = 0; right < s.length(); right++) {
      vec[s[right] - 'A']++;
      maxFre = max(maxFre, vec[s[right] - 'A']);
      while (right - left - maxFre + 1 > k) {
        vec[s[left]]--;
        left++;
      }

      ans = max(ans, right - left + 1);
    }
    return ans;
  }
};

int main() {
  Solution s;

  return 0;
}
