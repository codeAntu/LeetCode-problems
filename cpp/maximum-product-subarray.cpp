#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int maxProd = 1;
    int minProd = 1;
    int ans = INT_MIN;

    for (int num : nums) {
        int temp = maxProd;
        maxProd = max(num, maxProd * num);
        maxProd = max(maxProd, minProd * num);
        minProd = min(num, minProd * num);
        minProd = min(minProd, temp * num);
        ans = max(ans, maxProd);
    }
    return ans;
  }
};

int main() {
  Solution s;

  return 0;
}