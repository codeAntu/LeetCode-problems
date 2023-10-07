#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;


class Solution {
public:
   int findPeakElement(vector<int>& nums) {
      int low = 0, high = nums.size();
      int mid;
      bool pre, next;

      while (low < high)
      {
         pre = next = false;
         mid == (low + high) / 2;
         if (nums[mid] > nums[mid - 1]) pre = true;
         if (nums[mid] > nums[mid + 1]) next = true;
         if (pre && next) return mid;
         if (pre == false) high = mid;
         else if (next == false) low = mid;
      }
      return 0;
   }
};

int main() {
   Solution s;


   return 0;
}