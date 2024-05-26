#include "math.h"
#include "vector"

using namespace std;

class Solution {
  int mod = 1000000007;

public:
  int checkRecord(int n) {
    vector<vector<long>> DP(2, vector<long>(3, 1));

    for (int i = 0; i < n; i++) {
      vector<vector<long>> temp(2, vector<long>(3, 0));
      for (int a = 0; a < 2; a++) {
        for (int l = 0; l < 3; l++) {
          temp[a][l] += DP[a][2] % mod;                 // P
          if (a > 0) temp[a][l] += DP[a - 1][2] % mod;  // A
          if (l > 0) temp[a][l] += DP[a][l - 1] % mod;  // L
        }
      }
      DP = temp;
    }
    return DP[1][2] % mod;
  }
};
// Time limit EXCEEDED
// class Solution {
// public:
//     unordered_map<int, int> memo;
//     int checkRecord(int n, int a = 0, int l = 0) {
//     if (n == 0) return 1;
//     int mod = 1000000007;
//     int res = 0;
//     res = (res + checkRecord(n - 1, 0, 0)) % mod;
//     if (a < 1) res = (res + checkRecord(n - 1, 1, 0)) % mod;
//     if (l < 2) res = (res + checkRecord(n - 1, a, l + 1)) % mod;
//     memo[]
//     return res;
//   }
// };

int main() {
  Solution s;

  return 0;
}