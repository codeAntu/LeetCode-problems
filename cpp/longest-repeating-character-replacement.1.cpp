// class Solution {
// public:
//   int characterReplacement(string s, int k) {
//     int ans = 0;
//     int left = 0, right = 0;
//     vector<int> vec(26);
//     int maxFre = 0;

//     for (right = 0; right < s.length(); right++) {
//       vec[s[right]]++;
//       maxFre = max(maxFre, vec[s[right]]);
//       if (right - left - maxFre + 1 > k) {
//         vec[s[left]]--;
//         left++;
//       }

//       ans = max(ans, right - left + 1);
//     }
//     return ans;
//   }
// };

#include <string>
#include <vector>
class Solution {
public:
  int characterReplacement(std::string s, int k) {
    std::vector<int> vec(26);
    int left = 0, right = 0;
    int maxFre = 0;
    int ans = 0;

    while (right < s.size()) {
      vec[s[right] - 'A']++;
      maxFre = std::max(maxFre, vec[s[right] - 'A']);
      right++;

      if (right - left - maxFre > k) {
        vec[s[left] - 'A']--;
        left++;
      }

      ans = std::max(ans, right - left);
    }

    return 0;
  }
};
