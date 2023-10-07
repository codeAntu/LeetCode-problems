#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   vector<int> pivotArray(vector<int>& nums, int pivot) {
      int len = nums.size(), i, j = 0;
      vector<int> res(len);
      for (i = 0; i < len; i++) {
         if (nums[i] < pivot) {
            res[j] = nums[i];
            j++;
         }
      }
      for (i = 0; i < len; i++) {
         if (nums[i] == pivot) {
            res[j] = nums[i];
            j++;
         }
      }
      for (i = 0; i < len; i++) {
         if (nums[i] > pivot) {
            res[j] = nums[i];
            j++;
         }
      }
      return res;
   }
};


class Solution {
public:
   vector<int> pivotArray(vector<int>& nums, int pivot) {
      int len = nums.size();
      vector<int> res(len);
      int left = 0, right = len - 1;

      for (int i = 0; i < len;i++) {
         if (nums[i] < pivot) res[left++] = nums[i];
         if (nums[len - i - 1] > pivot) res[right--] = nums[len - i - 1];
      }

      while (left <= right) {
         res[left++] = pivot;
      }
      return res;
   }
};



int main() {
   Solution s;


   return 0;
}