#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

class Solution {
  public:
   vector<int> pathInZigZagTree(int label) {
      int n = log2(label);
      vector<int> ans(n + 1);
      while (n >= 0) {
         ans[n] = label;
         label = (pow(2, n) + pow(2, n + 1) - 1 - label) / 2;
         n--;
      }
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}
