#include <algorithm>
#include <unordered_map>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int i = 0; i < nums.size(); i++) {
      freq[nums[i]]++;
    }
    sort(nums.begin(), nums.end(),
         [&](int a, int b) { return freq[a] == freq[b] ? a > b : freq[a] < freq[b]; });
    return nums;
  }
};




int main() {
  Solution s;

  return 0;
}