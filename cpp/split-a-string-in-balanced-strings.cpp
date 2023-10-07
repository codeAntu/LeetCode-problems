#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int balancedStringSplit(string s) {
      int count = 0;
      int l = 0, r = 0;
      int n = s.length();
      for (int i = 0;i < n;i++) {
         if (s[i] == 'L') l++;
         else if (s[i] == 'R') r++;
         if (r == l) {
            count++;
            l = 0;
            r = 0;
         }
      }
      return count;
   }
};

int main() {
   Solution s;


   return 0;
}