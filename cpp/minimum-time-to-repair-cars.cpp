#include <cmath>
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
  long long repairCars(vector<int>& ranks, int cars) {
    long long l = 0, r = 1e14;
    int n = ranks.size();

    while (l <= r) {
      long long m = l + (r - l) / 2;
      long long totalCars = 0;
      for (int i = 0; i < n; i++) {
        totalCars += sqrt(m / ranks[i]);
      }
      if (totalCars >= cars) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    return l;
  }
};

int main() {
  Solution s;

  vector<int> ranks = {4, 2, 3, 1};
  int cars = 10;

  cout << s.repairCars(ranks, cars) << endl;

  return 0;
}
