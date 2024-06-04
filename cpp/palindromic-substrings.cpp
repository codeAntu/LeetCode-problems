#include "math.h"
#include "string"


using namespace std;

class Solution {
public:
  int countSubstrings(string s) {
    int n = s.size();
    int count = 0;
    int left, right;
    for (int i = 0; i < n; i++) {
      left = i;
      right = i;

      while (left >= 0 && right < n && s[left] == s[right]) {
        count++;
        left--;
        right++;
      }

      left = i;
      right = i + 1;

      while (left >= 0 && right < n && s[left] == s[right]) {
        count++;
        left--;
        right++;
      }
    }

    return count;
  }
};

int main() {
  Solution s;

  return 0;
}
