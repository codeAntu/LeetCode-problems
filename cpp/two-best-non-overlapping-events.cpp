#include <algorithm>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int maxTwoEvents(vector<vector<int>>& events) {
    int n = events.size();
    sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

    vector<int> suffixMax(n);
    suffixMax[n - 1] = events[n - 1][2];

    for (int i = n - 2; i >= 0; i--) {
      suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
      int left = i + 1, right = n - 1;

      int NextEvent = -1;

      while (left <= right) {
        int mid = left + (right - left) / 2;

        if (events[mid][0] > events[i][1]) {
          NextEvent = mid;
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }

      if (NextEvent != -1) {
        ans = max(ans, events[i][2] + suffixMax[NextEvent]);
      }

      ans = max(ans, events[i][2]);
    }

    return ans;
  }
};

int main() {
  Solution s;

  return 0;
}