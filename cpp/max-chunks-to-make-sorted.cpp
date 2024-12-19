#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int maxChunksToSorted(vector<int>& arr) {
    int n = arr.size();
    vector<int> maxLeft(n, 0);

    maxLeft[0] = arr[0];

    for (int i = 1; i < n; i++) {
      maxLeft[i] = max(maxLeft[i - 1], arr[i]);
    }

    int chunks = 0;

    for (int i = 0; i < n; i++) {
      if (maxLeft[i] == i) {
        chunks++;
      }
    }

    return chunks;
  }
};

int main() {
  Solution s;

  return 0;
}