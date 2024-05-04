#include <unordered_map>
#include "math.h"
#include "vector"

using namespace std;

// Given an integer array nums that does not contain any zeros, find the largest positive integer k
// such that -k also exists in the array. Return the positive integer k. If there is no such
// integer, return -1

class Solution {
public:
  int findMaxK(vector<int>& nums) {
    unordered_map<int , int> m;
    int maxK = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (m.find(-nums[i]) != m.end()) {
        maxK = max(maxK, abs(nums[i]));
      }
      m[nums[i]] = i;
    }
    return maxK;
  }
};

int main() {
  Solution s;

  return 0;
}