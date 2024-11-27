#include <algorithm>

#include "vector"

using namespace std;

class Solution {
public:
  int minGroups(vector<vector<int>>& intervals) {
    vector<int> start, end;
    int ans = 0;
    for (auto interval : intervals) {
      start.push_back(interval[0]);
      end.push_back(interval[1]);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    for(int i = 0, j = 0; i < start.size(); i++) {
      if (start[i] > end[j]) {
        j++;
      } else {
        ans++;
      }
    }

    return ans;
  }
};

int main() {
  Solution s;

  return 0;
}