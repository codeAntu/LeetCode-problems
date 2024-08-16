#include <algorithm>
#include "vector"

using namespace std;

class Solution {
public:
  int maxDistance(vector<vector<int>>& arrays) {
    int min = arrays[0][0];
    int max = arrays[0][arrays[0].size() - 1];
    int n = arrays.size();
    int res = 0;

    for (int i = 1; i < n; i++) {
      res = std::max(res, max - arrays[i][0]);
      res = std::max(res, arrays[i][arrays[i].size() - 1] - min);

      max = std::max(max, arrays[i][arrays[i].size() - 1]);
      min = std::min(min, arrays[i][0]);
    }
    return res;
  }
};

int main() {
  Solution s;

  return 0;
}