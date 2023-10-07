#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int countOdds(int low, int high) {
      return low & 1 ? (high - low) / 2 + 1 : (high - low + 1) / 2;
   }
};

int main() {
   Solution s;
   s.countOdds(8, 10);

   return 0;
}