#include <algorithm>
#include <queue>
#include <utility>
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int smallestChair(vector<vector<int>>& times, int targetFriend) {
    int n = times.size();
    vector<vector<int>> friends(n);
    priority_queue<int> chairs;
    priority_queue<pair<int, int>> usedChairs;

    for (int i = 0; i < n; i++) {
      friends[i] = {times[i][0], times[i][1], i};
    }

    for (int i = 0; i < n; i++) {
      chairs.push(-i);
    }

    sort(friends.begin(), friends.end());

    for (int i = 0; i < n; i++) {
      int arrival = friends[i][0];
      int leave = friends[i][1];
      int friendIndex = friends[i][2];

      while (!usedChairs.empty() && -usedChairs.top().first <= arrival) {
        chairs.push(-usedChairs.top().second);
        usedChairs.pop();
      }

      int chair = -chairs.top();
      chairs.pop();

      if (friendIndex == targetFriend) {
        return chair;
      }

      usedChairs.push({-leave, chair});
    }

    return -1;

  }
};

int main() {
  Solution s;

  return 0;
}