#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

class Solution {
  public:
   string truncateSentence(string s, int k) {
      string ans = "";
      for (int i = 0; i < s.size(); i++) {
         if (s[i] == ' ') k--;
         if (k == 0) break;
         ans += s[i];
      }
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}
