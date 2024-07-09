#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  double averageWaitingTime(vector<vector<int>>& customers) {
    double sum = 0;
    int n = customers.size();

    int time = 0;
    for (int i = 0; i < n; i++) {
      if (time < customers[i][0]) {
        time = customers[i][0];
      }
      time += customers[i][1];
      sum += time - customers[i][0];
    }

    return sum / n;
  }
};

int main() {
  Solution s;

  return 0;
}