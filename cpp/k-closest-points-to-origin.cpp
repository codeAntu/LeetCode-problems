#include <queue>


#include "math.h"
#include "vector"


using namespace std;
class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int, int>> pq;
    vector<vector<int>> res;
    for (int i = 0; i < points.size(); i++) {
      int x = points[i][0];
      int y = points[i][1];
      int dist = x * x + y * y;
      pq.push({dist, i});
      if (pq.size() > k) {
        pq.pop();
      }
    }
    while (!pq.empty()) {
      res.push_back(points[pq.top().second]);
      pq.pop();
    }
    return res;
  }
};

int main() {
  Solution s;

  return 0;
}