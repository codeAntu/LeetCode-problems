#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int numTeams(vector<int>& rating) {
    int res = 0;
    int n = rating.size();
    for (int i = 1; i < n - 1; i++) {
      int left_less = 0, left_more = 0, right_less = 0, right_more = 0;
      for (int j = 0; j < i; j++) {
        if (rating[j] < rating[i]) left_less++;
        if (rating[j] > rating[i]) left_more++;
      }
      for (int j = i + 1; j < n; j++) {
        if (rating[j] < rating[i]) right_less++;
        if (rating[j] > rating[i]) right_more++;
      }
      res += left_less * right_more + left_more * right_less;
    }

    return res;
  }
};

int main() {
  Solution s;

  return 0;
}