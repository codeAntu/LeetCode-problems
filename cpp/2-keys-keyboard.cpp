#include "iostream"
#include "math.h"

using namespace std;

class Solution {
public:
  int minSteps(int n) {
    int res = 0;
    for (int i = 2; i <= n; i++) {
      while (n % i == 0) {
        cout << "i: " << i << ", n: " << n << ", res: " << res << endl;

        res += i;
        n /= i;
      }
      cout << "i: " << i << ", n: " << n << ", res: " << res << endl;
    }
    return res;
  }
};

int main() {
  Solution s;

  cout << s.minSteps(25) << endl;

  return 0;
}
