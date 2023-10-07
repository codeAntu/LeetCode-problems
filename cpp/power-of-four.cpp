#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   bool isPowerOfFour(int n) {
      if (n == 1) return true;
      if (n < 4) return false;
      while (n > 1) {
         if (n % 4 != 0) return false;
         n = n / 4;
      }
      return true;
   }
};

int main() {
   Solution s;


   return 0;
}