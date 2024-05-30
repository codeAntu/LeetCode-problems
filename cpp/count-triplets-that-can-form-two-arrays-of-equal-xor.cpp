#include <unordered_map>

using namespace std;

class Solution {
public:
  int countTriplets(vector<int>& arr) {
    int n = arr.size();
    int ans = 0;
    int prefix = 0;
    unordered_map<int, int> cnt, total;
    cnt[0] = 1;

    for (int i = 0; i < n; i++) {
      prefix ^= arr[i];
      ans += cnt[prefix] * i - total[prefix];
      cnt[prefix]++;
      total[prefix] += i + 1;
    }

    return ans;
  }
};

int main() {
  Solution s;

  return 0;
}