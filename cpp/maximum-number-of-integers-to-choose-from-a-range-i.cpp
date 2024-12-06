#include <unordered_set>
using namespace std;

class Solution {
public:
  int maxCount(vector<int>& banned, int n, int maxSum) {
    unordered_set<int> bannedSet(banned.begin(), banned.end());

    int maxCount = 0;
    int sum = 0;

    for (int i = 1; i <= n; i++) {
      if (bannedSet.find(i) != bannedSet.end()) {
        continue;
      }
      if (sum + i > maxSum) {
        break;
      }
      sum += i;
      maxCount++;
    }

    return maxCount;
  }
};

int main() {
  Solution s;

  return 0;
}