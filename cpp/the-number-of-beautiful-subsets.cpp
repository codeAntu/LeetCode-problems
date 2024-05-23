#include <unordered_map>
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int res = 0;
  void dfs(vector<int>& nums, int k, unordered_map<int, int>& visited, int i, int n) {
    if (i == n) {
      if (visited.size()) res++;
      return;
    }

    dfs(nums, k, visited, i + 1, n);

    if (visited.find(nums[i] - k) != visited.end() || visited.find(nums[i] + k) != visited.end() )
      return;

    visited[nums[i]]++;
    dfs(nums, k, visited, i + 1, n);
    if (visited[nums[i]] == 1)
      visited.erase(nums[i]);
    else
      visited[nums[i]]--;
    return;
  }
  int beautifulSubsets(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> visited;
    dfs(nums, k, visited, 0, n);
    return res;
  }
};

int main() {
  Solution s;

  return 0;
}