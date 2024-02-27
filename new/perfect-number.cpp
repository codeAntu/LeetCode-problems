
#include "stdio.h"
#include <cmath>

class Solution {
public:
  bool checkPerfectNumber(int num) {
    int sum = 1;
    if (num == 1)
      return false;
    for (int i = 2; i < std::sqrt(num); i++) {
      if (num % i == 0) {
        sum += i;
        sum += num / i;
      }
    }
    return sum == num;
  }
};

int main() {
  Solution s;
  printf("%d\n", s.checkPerfectNumber(28));
  printf("hello world\n");
  return 0;
}
