#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include <unordered_set>

using namespace std;

class Solution {
public:
   bool containsDuplicate(vector<int>& nums) {
      unordered_set<int> hash;
      int n = nums.size();
      for (int i = 0; i < n; i++)
      {
         if (hash.count(nums[i]))   return true;
         hash.insert(nums[i]);
      }
      return false;
   }
};

int main() {
   Solution s;


   return 0;
}