#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int subtractProductAndSum(int n) {
      int sum = 0, product = 1;

      while (n) {
         sum += n % 10;
         product *= n % 10;
         n = n / 10;
      }
      return product - sum;
   }
};

int main() {
   Solution s;


   return 0;
}