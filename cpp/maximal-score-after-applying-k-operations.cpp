#include <queue>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  long long maxKelements(vector<int>& nums, int k) {
    priority_queue<int> pq;
    long long res = 0;
    int i = 0;

    for (int i = 0; i < nums.size(); i++) {
      pq.push(nums[i]);
    }

    while (i < k) {
      int top = pq.top();
      pq.pop();
      res += top;
      pq.push(ceil(top / 3.0));
      i++;
    }

    return res;
  }
};

int main() {
  Solution s;

  return 0;
}