#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;


class Solution {
public:
   int addDigits(int num) {
      int sum = 0;
      while (num > 9)
      {
         sum = 0;
         while (num)
         {
            sum += num % 10;
            num /= 10;
         }
         if (sum < 10) return sum;
         else num = sum;
      }
      return num;
   }
};

int main() {
   Solution s;

   s.addDigits(38);

   return 0;
}