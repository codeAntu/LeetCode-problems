#include <stack>
#include <utility>

#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int max = 0;
    stack<pair<int, int>> s;
    int start = 0;
    for (int i = 0; i < heights.size(); i++) {
      start = i;
      while (!s.empty() && s.top().second > heights[i]) {
        pair<int, int> curr = s.top();
        s.pop();
        max = std::max(max, curr.second * (i - curr.first));
        start = curr.first;
      }
      s.push({start, heights[i]});
    }

    while (!s.empty()) {
      pair<int, int> curr = s.top();
      s.pop();
      max = max > curr.second * (heights.size() - curr.first)
                ? max
                : curr.second * (heights.size() - curr.first);
    }

    return max;
  }
};

int main() {
  Solution s;

  return 0;
}