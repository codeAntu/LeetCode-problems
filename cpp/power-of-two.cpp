#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   bool isPowerOfTwo(int n) {
      return n > 0 && !(n & n - 1);
   }
};

main() {
   Solution s;


   return 0;
};