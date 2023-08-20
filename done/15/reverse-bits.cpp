#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   uint32_t reverseBits(uint32_t n) {
      if (n == 0) return 0;
      int  ans = 0;
      for (int i = 0; i < 32; i++)
      {
         ans = ans | (((n >> i) & 1) << (31 - i));
      }
      return ans;
   }
};


int main() {
   Solution s;


   return 0;
}