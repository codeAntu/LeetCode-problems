#include "iostream"
#include "math.h"

using namespace std;

class Solution {
public:
  int getSum(int a, int b) {
    while (b != 0) {
      int carry = a & b;
      a = a ^ b;
      b = carry << 1;
    }
    return a;
  }
};

int main() {
  Solution s;
  cout << s.getSum(1, 2) << endl;
  return 0;
}