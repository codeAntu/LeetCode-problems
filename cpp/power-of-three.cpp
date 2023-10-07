#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   bool isPowerOfThree(int n) {
      if (n == 1) return true;
      if (n < 3) return false;
      while (n > 1) {
         if (n % 3 != 0) return false;
         n = n / 3;
      }
      return true;

   }
};

int main() {
   Solution s;


   return 0;
}