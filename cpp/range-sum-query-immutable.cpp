#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class NumArray {
public:
   vector<int>& sums;
   NumArray(vector<int>& nums) : sums(nums) {
      for (int i = 1; i < sums.size();i++) {
         sums[i] += sums[i - 1];
      }
   }
   int sumRange(int left, int right) {
      return left ? sums[right] - sums[left - 1] : sums[right];
   }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main() {


   return 0;
}