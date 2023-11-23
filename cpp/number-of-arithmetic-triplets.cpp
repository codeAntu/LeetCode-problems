#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

class Solution {
  public:
   int arithmeticTriplets(vector<int>& nums, int diff) {
    
   }
};

// class Solution {
// public:
//     int arithmeticTriplets(vector<int>& nums, int diff) {

//         vector<int> hash(305,0); // for storing cnt of each element in the array
//         for(int i = 0 ; i < nums.size();i++){
//             hash[nums[i]]++; // storing cnt
//         }
//         int sum = 0;
//         for(int i = 0 ; i < nums.size();i++){
//              if(hash[nums[i] + diff] > 0 && hash[nums[i] + diff + diff] > 0) // as array is sorted - > ![image](https://assets.leetcode.com/users/images/524cf4f9-57df-4ee6-9a86-567aa16b69c1_1665212577.6177518.png)
// i < j < k for all nums[i] < nums[j] < nums[j]
//                   sum++;
//         }
//         return sum;

//     }
// };

int main() {
   Solution s;

   return 0;
}
