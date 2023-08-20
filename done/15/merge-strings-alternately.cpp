#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   string mergeAlternately(string word1, string word2) {
      int n = word1.length(), m = word2.length();
      string ans = "";

      for (int i = 0; i < m || i < n; i++)
      {
         if (i < n) ans += word1[i];
         if (i < m) ans += word2[i];
      }
      return ans;
   }
};

int main() {
   Solution s;


   return 0;
}