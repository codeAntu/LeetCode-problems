#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int sumIndicesWithKSetBits(vector<int>& nums, int k) {
      int sum = 0, count, temp;
      for (int i = 0; i < nums.size(); i++) {
         count = 0;
         temp = i;
         while (temp) {
            if (temp & 1)
               count++;
            temp >>= 1;
         }
         if (count == k)
            sum += nums[i];
      }
      return sum;
   }
};

int main() {
   Solution s;


   return 0;
}