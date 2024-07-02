#include <algorithm>
#include <queue>
#include <utility>

#include "iostream"
#include "math.h"
#include "vector"


using namespace std;

class Solution {
public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n = quality.size();
    vector<pair<double, int>> ratio(n);
    for (int i = 0; i < n; i++) {
      ratio[i] = {double(wage[i]) / quality[i], quality[i]};
    }
    sort(ratio.begin(), ratio.end());
    double ans = 1e9;
    int sum = 0;

    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
      sum += ratio[i].second;
      pq.push(ratio[i].second);
      if (pq.size() > k) {
        sum -= pq.top();
        pq.pop();
      }
      if (pq.size() == k) {
        ans = min(ans, sum * ratio[i].first);
      }
    }

    return ans;
  }
};

int main() {
  Solution s;

  return 0;
}