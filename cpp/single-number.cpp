#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

// done 
class Solution {
public:
   int singleNumber(vector<int>& nums) {
      int ans;
      for (int i = 1; i < nums.size(); i++)
      {
         nums[0] ^= nums[i];
      }
      return nums[0];
   }
};
// class Solution {
// public:
//    int singleNumber(vector<int>& nums) {
//       int ans = 0;
//       for (int i = 0; i < nums.size(); i++)
//       {
//          ans = ans ^ nums[i];
//       }
//       return ans;
//    }
// };


int main() {
   Solution s;


   return 0;
}