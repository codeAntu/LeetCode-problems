#include <string>
using namespace std;

class Solution {
 public:
   int countBinarySubstrings(string s) {
      int counts[2];
      int ans = 0;

      counts[s[0] - '0'] = 1;

      for (int i = 1; i < s.length(); i++) {
         if (s[i] == s[i - 1]) {
            counts[s[i] - '0']++;
         } else {
            ans += min(counts[0], counts[1]);
            counts[s[i] - '0'] = 1;
         }
      }
      ans += min(counts[0], counts[1]);
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}