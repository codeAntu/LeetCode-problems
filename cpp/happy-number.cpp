#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;
// done

class Solution {
public:
   bool isHappy(int n) {
      int sum;
      while (n > 9)
      {
         sum = 0;
         while (n)
         {
            sum += pow(n % 10, 2);
            n /= 10;
         }
         n = sum;
      }
      if (n == 1 || n == 7)
         return true;
      return false;
   }
};




int main() {
   Solution s;


   return 0;
}