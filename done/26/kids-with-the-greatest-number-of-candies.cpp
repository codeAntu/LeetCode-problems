#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
      int max = candies[0], n = candies.size(), i;
      vector<bool> ans(n, false);

      for (i = 0; i < n; i++) {
         if (candies[i] > max) max = candies[i];
      }
      for (i = 0; i < n; i++) {
         if (candies[i] + extraCandies >= max) ans[i] = true;
      }
      return ans;
   }
};

int main() {
   Solution s;


   return 0;
}