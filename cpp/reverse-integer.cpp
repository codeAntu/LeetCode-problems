#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int reverse(int x) {
      long int ans = 0;
      while (x) {
         ans *= 10;
         ans += x % 10;
         x /= 10;
      }
      if (ans > INT_MAX) return 0;
      if (ans < INT_MIN) return 0;
      return ans;
   }
};

int main() {
   Solution s;

   cout << s.reverse(-123);

   return 0;
}