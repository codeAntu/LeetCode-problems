#include "map"
#include "vector"

using namespace std;

class Solution {
public:
  vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    map<int, int> m;
    vector<vector<int>> res;
    for (int i = 0; i < nums1.size(); i++) {
      m[nums1[i][0]] += nums1[i][1];
    }

    for (int i = 0; i < nums2.size(); i++) {
      m[nums2[i][0]] += nums2[i][1];
    }

    for (auto it = m.begin(); it != m.end(); it++) {
      res.push_back({it->first, it->second});
    }

    return res;
  }
};

int main() {
  Solution s;

  return 0;
}