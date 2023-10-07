#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   bool isSubsequence(string s, string t) {
      int i = 0, j = 0, len1 = t.length(), len2 = s.length();
      while (i < len1 && j < len2) {
         if (s[j] == t[i]) j++;
         i++;
      }
      if (j == len2) return true;
      return false;
   }
};

int main() {
   Solution s;


   return 0;
}