#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  void dfs(vector<int>& candidates, int target, int index, vector<int>& current,
           vector<vector<int>>& result) {
    if (target == 0) {
      result.push_back(current);
      return;
    }

    if (index == candidates.size()) {
      return;
    }

    if (candidates[index] <= target) {
      current.push_back(candidates[index]);
      dfs(candidates, target - candidates[index], index, current, result);
      current.pop_back();
    }

    dfs(candidates, target, index + 1, current, result);
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    dfs(candidates, target, 0, current, result);
    return result;
  }
};

int main() {
  Solution s;

  return 0;
}