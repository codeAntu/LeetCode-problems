#include "iostream"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  vector<int> closestPrimes(int left, int right) {
    vector<int> primes;
    vector<bool> nums(right + 1, true);
    vector<int> res(2, -1);
    int minDiff = INT_MAX;
    nums[0] = nums[1] = false;

    for (int i = 2; i <= sqrt(right) + 1; i++) {
      if (nums[i]) {
        for (int j = i * i; j <= right; j += i) {
          nums[j] = false;
        }
      }
    }

    for (int i = left; i <= right; i++) {
      if (nums[i]) {
        primes.push_back(i);
      }
    }

    if (primes.size() < 2) {
      return res;
    }

    for (int i = 0; i < primes.size() - 1; i++) {
      if (primes[i + 1] - primes[i] < minDiff) {
        minDiff = primes[i + 1] - primes[i];
        res[0] = primes[i];
        res[1] = primes[i + 1];
      }
    }

    return res;
  }
};

int main() {
  Solution s;

  vector<int> res = s.closestPrimes(628853, 801856);

  cout << "res: ";
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }

  return 0;
}