#include "iostream"
#include "map"
#include "math.h"
#include "unordered_map"
#include "vector"
using namespace std;

class Solution {
  public:
   int reductionOperations(vector<int>& nums) {
      map<int, int> m;
      for (int i = 0; i < nums.size(); i++) {
         m[nums[i]]++;
      }
      int ans = 0;
      int prev = 0;
      for (auto it = m.end(); it != m.begin(); it--) {
         ans += prev + it->second;
         prev += it->second;
      }
      return ans;
   }
};

class Solution {
  public:
   int reductionOperations(vector<int>& nums) {
      unordered_map<int, int> m;
      int mini = INT_MAX;
      int n = nums.size();
      for (int i = 0; i < n; i++) {
         m[nums[i]]++;
         mini = min(mini, nums[i]);
      }
      int ans = 0;
      int prev = 0;
      for (auto it = m.begin(); it != m.end(); it++) {
         if (it->first == mini) continue;
         ans += n - (prev + it->second);
         prev += it->second;
      }
      return ans;
   }
};

// static const int _ = []() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    return 0;
// }();

// class Solution {
//   public:
//    int arr[50001];
//    int reductionOperations(vector<int>& nums) {
//       memset(arr, 0, sizeof(arr));
//       int mini = INT_MAX, maxi = INT_MIN;
//       for (int& n : nums) {
//          ++arr[n];
//          mini = min(n, mini);
//          maxi = max(n, maxi);
//       }
//       int res = 0, cnt = arr[mini];
//       for (int i = mini + 1; i <= maxi; i++) {
//          if (arr[i] > 0) {
//             res += nums.size() - cnt;
//          }
//          cnt += arr[i];
//       }

//       return res;
//    }
// };

int main() {
   Solution s;

   return 0;
}
