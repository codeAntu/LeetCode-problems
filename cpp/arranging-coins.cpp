#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
  int arrangeCoins(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
      count++;
      n -= i;
    }
    return count;
  }
};

int main() {
  Solution s;


  return 0;
}
