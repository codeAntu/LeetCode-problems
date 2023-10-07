#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include "set"
#include <bits/stdc++.h>
using namespace std;

// failed 
// class Solution {
// public:
//    int maxOperations(vector<int>& nums, int k) {
//       multiset<int> mset;
//       int len = nums.size(), count = 0;
//       multiset<int> ::iterator itr1, itr2;
//       for (int i = 0; i < len; i++) {
//          mset.insert(nums[i]);
//       }

//       for (int i = 0; i < len; i++) {
//          if (nums[i] == k - nums[i]) {
//             int n = mset.count(nums[i]);
//             if (n > 1) {
//                itr1 = mset.find(nums[i]);
//                mset.erase(itr1);
//                itr1 = mset.find(nums[i]);
//                mset.erase(itr1);
//                count++;
//             }
//          } else {
//             itr1 = mset.find(nums[i]);
//             itr2 = mset.find(k - nums[i]);
//             if (itr1 != mset.end() && itr2 != mset.end()) {
//                count++;
//                mset.erase(itr1);
//                mset.erase(itr2);
//             }
//          }
//       }

//       return count;
//    }
// };

class Solution {
public:
   int maxOperations(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end());
      int left = 0, right = nums.size() - 1, count = 0;

      while (left < right) {
         if (nums[left] == k - nums[right]) {
            count++;
            left++;
            right--;
         } else if (nums[left] > k - nums[right]) right--;
         else left++;
      }
      return count;
   }
};

int main() {
   Solution s;


   return 0;
}