#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;


class Solution {
public:
   bool repeatedSubstringPattern(string s) {
      int n = s.length();
      bool x = 0;
      for (int i = 1; i <= n / 2; i++)
      {
         if (n % i == 0) {
            string sub = s.substr(0, i);
            x = 0;
            for (int j = i; j < n; j += i) {
               for (int k = 0; k < i; k++)
               {
                  if (sub[k] != s[k + j])
                  {
                     x = 1;
                     break;
                  }
               }
               if (x) break;
            }
            if (x == 0) return true;
         }
      }
      return false;
   }
};

int main() {
   Solution s;


   return 0;
}