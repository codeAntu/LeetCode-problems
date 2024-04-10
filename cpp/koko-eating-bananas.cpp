#include "vector"

using namespace std;

class Solution {
public:
  bool ifFinished(vector<int>& piles, int k, int t) {
    int time = 0;
    for (int i = 0; i < piles.size(); i++) {
      time += (piles[i] + k - 1) / k;
    }
    return time <= t;
  }

  int minEatingSpeed(vector<int>& piles, int h) {
    int res = 0;
    int low = 0, high = 0;

    for (auto pile : piles) {
      if (pile > high) high = pile;
    }

    while (low < high) {
      int mid = low + (high - low) / 2;
      if (ifFinished(piles, mid, h)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }

    return low;
  }
};

int main() {
  Solution s;

  return 0;
}