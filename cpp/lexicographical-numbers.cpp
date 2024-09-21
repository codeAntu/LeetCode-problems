#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  vector<int> lexicalOrder(int n) {
    vector<int> res;
    int cur = 1;
    for (int i = 1; i <= n; i++) {
      res.push_back(cur);
      if (cur * 10 <= n) {
        cur *= 10;
      } else if (cur % 10 != 9 && cur + 1 <= n) {
        cur++;
      } else {
        while ((cur / 10) % 10 == 9) {
          cur /= 10;
        }
        cur = cur / 10 + 1;
      }
    }
    return res;
  }
};



int main() {
  Solution s;

  return 0;
}