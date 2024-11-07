#include "math.h"
#include "vector"

using namespace std;

class Solution {
  vector<int> prefixSum;
  int totalSum;

public:
  Solution(vector<int>& w) {
    totalSum = 0;
    for (int weight : w) {
      totalSum += weight;
      prefixSum.push_back(totalSum);
    }
  }

  int pickIndex() {
    int random = rand() % totalSum;
    int left = 0;
    int right = prefixSum.size() - 1;

    while (left < right) {
      int mid = left + (right - left) / 2;
      if (random >= prefixSum[mid]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left;
  }
};

int main() {

  return 0;
}