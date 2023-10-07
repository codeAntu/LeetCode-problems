#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;
class Solution {
public:
   vector<int> countBits(int n) {
      vector<int> ans(n + 1, 0);

      for (int i = 0; i <= n; i++)
      {
         int temp = i, count = 0;

         while (temp)
         {
            count += temp & 1;
            temp >>= 1;
         }
         ans[i] = count;
      }
      return ans;
   }
};


int main() {
   Solution s;


   return 0;
}