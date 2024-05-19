#include <algorithm>
#include "iostream"
#include "math.h"
#include "vector"

using namespace std;

// class Solution {
// public:
//   long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
//     vector<int> inc(nums.size(), 0);
//     long long res = 0;

//     for (int i = 0; i < nums.size(); i++) {
//       inc[i] = (nums[i] ^ k) - nums[i];
//     }

//     sort(inc.begin(), inc.end(), greater<int>());

//     for (int num : nums) {
//       res += num;
//     }
//     for (int i = 0; i < nums.size() ; i+= 2) {
//       if (i == nums.size() - 1) break;
//       int d = inc[i] + inc[i + 1];
//       if (d <= 0) break;

//       res += d;
//     }

//     return res;
//   }
// };

class Solution {
public:
  long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
    long long res = 0;
    int count = 0;
    int extra = INT_MAX;

    cout << "extra" << extra << endl;
    for (int num : nums) {
      int xorNum = num ^ k;
      if (xorNum > num) {
        res += xorNum;
        count++;
        extra = min(extra, xorNum - num);
      } else {
        res += num;
        extra = min(extra, num - xorNum);
      }
    }

    if (count % 2) {
      res -= extra;
    }
    return res;
  }
};


int main() {
  Solution s;

  //  [24,78,1,97,44]
  // [[0,2],[1,2],[4,2],[3,4]]
  // 6

  vector<int> nums = {24, 78, 1, 97, 44};
  int k = 6;
  vector<vector<int>> edges = {{0, 2}, {1, 2}, {4, 2}, {3, 4}};

  cout << s.maximumValueSum(nums, k, edges) << endl;

  return 0;
}