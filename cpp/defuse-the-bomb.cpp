#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();
    vector<int> res(n, 0);
    if (k == 0) {
      return res;
    }

    int sum = 0;
    int start, end;

    if (k > 0) {
      start = 1;
      end = k;
    } else {
      start = k;
      end = -1;
    }

    for (int j = start; j <= end; ++j) {
      sum += code[(0 + j + n) % n];
    }

    for (int i = 0; i < n; ++i) {
      res[i] = sum;
      sum -= code[(i + start + n) % n];
      sum += code[(i + end + 1 + n) % n];
    }

    return res;
  }
};

int main() {
  Solution s;

  return 0;
}