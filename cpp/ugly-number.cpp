#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   bool isUgly(int n) {
      if (n < 1)
      {
         return false;
      }
      while (n % 2 == 0)
      {
         n /= 2;
      }
      while (n % 3 == 0)
      {
         n /= 3;
      }
      while (n % 5 == 0)
      {
         n /= 5;
      }
      return n == 1;
   }
};


int main() {
   Solution s;


   return 0;
}