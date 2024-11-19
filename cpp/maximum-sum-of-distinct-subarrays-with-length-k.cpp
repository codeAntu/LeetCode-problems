#include <unordered_map>
#include <unordered_set>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    int n = nums.size();
    long long sum = 0;
    long long max_sum = 0;

    for (int i = 0; i < k; i++) {
      sum += nums[i];
      freq[nums[i]]++;
    }

    if (freq.size() == k) {
      max_sum = sum;
    }
    for (int i = k; i < n; i++) {
      sum += nums[i];
      freq[nums[i]]++;
      sum -= nums[i - k];
      
      if (freq[nums[i - k]] == 1) {
        freq.erase(nums[i - k]);
      } else {
        freq[nums[i - k]]--;
      }

      if (freq.size() == k) {
        max_sum = max(max_sum, sum);
      }
    }

    return max_sum;
  }
};

int main() {
  Solution s;

  return 0;
}