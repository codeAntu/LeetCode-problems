#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  bool canArrange(vector<int>& arr, int k) {
    vector<int> freq(k, 0);

    for (int i = 0; i < arr.size(); i++) {
      int mod = arr[i] % k;
      if (mod < 0) mod += k;
      freq[mod]++;
    }

    if (freq[0] % 2 != 0) return false;

    for (int i = 1; i <= k / 2; i++) {
      if (freq[i] != freq[k - i]) return false;
    }

    return true;
  }
};

int main() {
  Solution s;

  return 0;
}