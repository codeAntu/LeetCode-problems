#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
  int hammingDistance(int x, int y) {
    int count = 0;

    for (int i = 0; i < 32; i++) {
      if ((x & 1) != (y & 1)) {
        count++;
      }
      x >>= 1;
      y >>= 1;
    }

    return count;
  }
};

int main() {
  Solution s;


  return 0;
}
