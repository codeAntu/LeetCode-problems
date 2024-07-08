#include <deque>

#include "math.h"

using namespace std;

// class Solution {
// public:
//   int findTheWinner(int n, int k) {
//     vector<int> v(n);
//     for (int i = 0; i < n; i++) {
//       v[i] = i + 1;
//     }
//     int i = 0;
//     while (v.size() > 1) {
//       i = (i + k - 1) % v.size();
//       v.erase(v.begin() + i);
//     }
//     return v[0];
//   }
// };

// class Solution {
// public:
//   int findTheWinner(int n, int k) {
//     int res = 0;
//     for (int i = 1; i <= n; i++) {
//       res = (res + k) % i;
//     }
//     return res + 1;
//   }
// };

class Solution {
public:
  int findTheWinner(int n, int k) {
    deque<int> q;
    for (int i = 1; i <= n; i++) {
      q.push_back(i);
    }
    while (q.size() > 1) {
      for (int i = 0; i < k - 1; i++) {
        q.push_back(q.front());
        q.pop_front();
      }
      q.pop_front();
    }
    return q.front();
  }
};

int main() {
  Solution s;

  return 0;
}