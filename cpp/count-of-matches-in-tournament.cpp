#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int numberOfMatches(int n) {
      int ans = 0;

      while (n > 1)
      {
         ans += n / 2;
         n = n % 2 ? (n + 1) / 2 : n / 2;
      }
      return ans;
   }
};

int main() {
   Solution s;

   s.numberOfMatches(7);

   return 0;
}