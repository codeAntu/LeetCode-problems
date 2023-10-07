#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include "unordered_map"
#include "unordered_set"
using namespace std;

class Solution {
public:
   int numIdenticalPairs(vector<int>& nums) {
      unordered_map<int, int> m;
      int count = 0;

      for (int i = 0; i < nums.size(); i++) {
         m[nums[i]]++;
      }
      for (int i = 0; i < nums.size();i++) {
         if (m[nums[i]] > 1) {
            count += m[nums[i]] - 1;
            m[nums[i]]--;
         }
      }
      return count;
   }
};

int main() {
   Solution s;


   return 0;
}