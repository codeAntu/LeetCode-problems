#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

class Solution {
  public:
   int bitwiseComplement(int n) {
      int ans = 1;

      while ((ans & n) != n) {
         ans = ans << 1;
         ans += 1;
      }
      return ans ^ n;
   }
};

int main() {
   Solution s;

   return 0;
}
