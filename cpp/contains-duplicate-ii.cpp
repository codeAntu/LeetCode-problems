#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include "unordered_map"
using namespace std;

class Solution {
public:
   bool containsNearbyDuplicate(vector<int>& nums, int k) {

      unordered_map<int, int> hmap;
      int n = nums.size();
      for (int i = 0; i < n; i++)
      {
         if (hmap.find(nums[i]) != hmap.end() && i - hmap[nums[i]] <= k)  return true;
         hmap[nums[i]] = i;
      }
      return false;
   }
};

int main() {
   Solution s;


   return 0;
}