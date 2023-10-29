#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

class Solution {
  public:
   int sumOfMultiples(int n) {
      int sum = 0;
      for (int i = 1; i <= n; i++) {
         if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
            sum += i;
         }
      }
      return sum;
   }
};

int main() {
   Solution s;

   return 0;
}
