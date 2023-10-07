#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   vector<int> runningSum(vector<int>& nums) {
      int size = nums.size();
      vector<int> res(size);
      int sum = 0;
      for (int i = 0; i < size; i++) {
         res[i] = sum+= nums[i];
      }
      return res;
   }
};

int main() {
   Solution s;


   return 0;
}