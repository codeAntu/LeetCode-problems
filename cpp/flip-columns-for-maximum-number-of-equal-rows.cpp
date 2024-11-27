#include <string>
#include <unordered_map>
#include "vector"

using namespace std;

class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    unordered_map<string, int> mp;

    for (auto row : matrix) {
      string s;
      if (row[0] == 0) {
        for (auto i : row) {
          s += to_string(i);
        }
      } else {
        for (auto i : row) {
          s += to_string(1 ^ i);
        }
      }

      mp[s]++;
    }

    int res = 0;

    for (auto [_, v] : mp) {
      res = max(res, v);
    }

    return res;
  }
};

int main() {
  Solution s;

  return 0;
}