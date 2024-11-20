#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int takeCharacters(string s, int k) {
    int n = s.size();
    int arr[3] = {0};

    for (int i = 0; i < n; i++) {
      arr[s[i] - 'a']++;
    }

    if (arr[0] < k || arr[1] < k || arr[2] < k) {
      return -1;
    }

    // sliding window
    int left = 0;
    int right = 0;

    int ans = 0;

    while (right < n) {
      arr[s[right] - 'a']--;

      while (arr[0] < k || arr[1] < k || arr[2] < k) {
        arr[s[left] - 'a']++;
        left++;
      }

      ans = max(ans, right - left + 1);
      right++;
    }

    return n - ans;
  }
};

int main() {
  Solution s;

  return 0;
}