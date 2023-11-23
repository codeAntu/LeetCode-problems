#include "iostream"
#include "map"
#include "math.h"
#include "vector"
// #include "algorithm"
using namespace std;

class Solution {
  public:
   string licenseKeyFormatting(string s, int k) {
      string ans = "";
      int n = s.size();
      for (int i = n - 1; i >= 0; i--) {
         if (s[i] != '-') {
            if (ans.size() % (k + 1) == k) ans += '-';
            ans += toupper(s[i]);
         }
      }
      reverse(ans.begin(), ans.end());
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}
