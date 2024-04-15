#include <algorithm>
#include "math.h"
#include "vector"

using namespace std;

// class Solution {
// public:
//   int leastInterval(vector<char>& tasks, int n) {
//     vector<int> count(26, 0);
//     for (char c : tasks) {
//       count[c - 'A']++;
//     }
//     priority_queue<int> pq;
//     for (int i = 0; i < 26; i++) {
//       if (count[i] > 0) {
//         pq.push(count[i]);
//       }
//     }
//     int time = 0;
//     queue<pair<int, int>> q;
//     while (!pq.empty() || !q.empty()) {
//       if (!pq.empty()) {
//         int top = pq.top();
//         pq.pop();
//         top--;
//         if (top > 0) {
//           q.push({top, time + n + 1});
//         }
//       }
//       time++;
//       if (!q.empty() && q.front().second == time) {
//         pq.push(q.front().first);
//         q.pop();
//       }
//     }
//     return time;
//   }
// };

class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    int fre[26] = {0};
    int maxCount = 0;
    for (char c : tasks) {
      int x = ++fre[c - 'A'];
      maxCount = max(maxCount, x);
    }
    int numMax = count(fre, fre + 26, maxCount);
    return max((maxCount - 1) * (n + 1) + numMax, (int)tasks.size());
  }
};

int main() {
  Solution s;

  return 0;
}
