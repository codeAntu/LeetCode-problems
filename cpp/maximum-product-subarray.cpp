#include "math.h"
#include "vector"

using namespace std;

// class Solution {
// public:
//   int maxProduct(vector<int>& nums) {
//     int n = nums.size();
//     double maxProd = INT_MIN;
//     double prod = 1;

//     for (int i = 0; i < n; i++) {
//       prod *= nums[i];
//       maxProd = max(maxProd, prod);
//       if (prod == 0) {
//         prod = 1;
//       }
//     }
//     prod = 1;
//     for (int i = n - 1; i >= 0; i--) {
//       prod *= nums[i];
//       maxProd = max(maxProd, prod);
//       if (prod == 0) {
//         prod = 1;
//       }
//     }
//     return maxProd;
//   }
// };

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size();
    double maxProd = INT_MIN;
    double prod1 = 1;
    double prod2 = 1;

    for (int i = 0; i < n; i++) {
      prod1 *= nums[i];
      prod2 *= nums[n - i - 1];

      maxProd = max(maxProd, prod1);
      maxProd = max(maxProd, prod2);

      if (prod1 == 0) prod1 = 1;
      if (prod2 == 0) prod2 = 1;
    }

    return maxProd;
  }
};

int main() {
  Solution s;

  return 0;
}