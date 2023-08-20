#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;
class Solution {
public:
   bool isMonotonic(vector<int>& nums) {
   bool dec = true, inc = true;
   for (int i = 0; i < nums.size() - 1; i++)
   {
      if (nums[i] > nums[i + 1]) inc = false;
      if (nums[i] < nums[i + 1]) dec = false;

   }
   return dec || inc;
}

};

class Solution {
public:
   bool isMonotonic(vector<int>& nums) {
   bool dec = false, inc = false;
   for (int i = 0; i < nums.size() - 1; i++)
   {
      if (nums[i] > nums[i + 1]) dec = true;
      else if (nums[i] < nums[i + 1]) inc = true;
      if(dec & inc) return false;

   }
   return dec || inc;
}
};
class Solution {
public:

   bool isMonotonic(vector<int>& nums) {
      int n = nums.size() - 1, i = 0, inc = 0;
      while (i < n)
      {
         if (nums[i] > nums[i + 1]) {
            break;
         }
         if (nums[i] < nums[i + 1]) {
            inc = 1;
            break;
         }
         i++;
      }
      if (inc) {
         while (i < n)
         {
            if (nums[i] > nums[i + 1]) return false;
            i++;
         }
      } else {
         while (i < n)
         {
            if (nums[i] < nums[i + 1]) return false;
            i++;
         }

      }

      return true;
   }
};

class Solution {
public:

   bool isMonotonic(vector<int>& nums) {
      int n = nums.size() - 1, i = 0, ind = 0;
      while (i < n)
      {
         if (nums[i] > nums[i + 1]) {
            ind = -1;
            break;
         }
         if (nums[i] < nums[i + 1]) {
            ind = 1;
            break;
         }
         i++;
      }
      while (i < n && ind)
      {
         if (nums[i] * ind > nums[i + 1] * ind) return false;
         i++;
      }

      return true;
   }
};

class Solution {
public:
   bool isDecrease(vector<int> nums, int i, int n) {
      while (i < n)
      {
         if (nums[i] < nums[i + 1]) return false;
         i++;
      }
      return true;

   }
   bool isIncrease(vector<int> nums, int i, int n) {
      while (i < n)
      {
         if (nums[i] > nums[i + 1]) return false;
         i++;
      }
      return true;

   }
   bool isMonotonic(vector<int>& nums) {
      int n = nums.size() - 1;
      for (int i = 0; i < n; i++)
      {
         if (nums[i] > nums[i + 1]) return isDecrease(nums, i, n);
         if (nums[i] < nums[i + 1]) return isIncrease(nums, i, n);

      }
      return true;
   }
};




int main() {
   Solution s;
   int i = 0;
   for (i = 0; i < 5; i++)
   {
      if (i == 3) break;
   }
   cout << i;

   return 0;
}
