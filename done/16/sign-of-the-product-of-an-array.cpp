#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int arraySign(vector<int>& nums) {
      int product = 1;
      for (int n : nums) product = (product* 1ll * n) % INT_MAX;
      if (product > 0) return 1;
      if (product < 0) return -1;
      return 0;

   }
};

int main() {
   Solution s;


   return 0;
}