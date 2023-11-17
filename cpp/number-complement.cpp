#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

class Solution {
  public:
   int findComplement(int num) {
      int ans = num;
      int c = 1;
      while (num != 0) {
         ans = ans ^ c;
         c = c << 1;
         num = num >> 1;
      }
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}
