#include "math.h"

using namespace std;

class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    return numBottles + (numBottles - 1) / (numExchange - 1);
  }
};

int main() {
  Solution s;

  return 0;
}