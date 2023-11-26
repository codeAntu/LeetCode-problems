#include "iostream"
#include "map"
#include "math.h"
#include "stack"
#include "unordered_map"
#include "vector"
using namespace std;

class Solution {
  public:
   vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      unordered_map<int, int> m;
      stack<int> s;
      int n = nums1.size();
      vector<int> ans(n, -1);

      for (int n : nums2) {
         while (!s.empty() && s.top() < n) {
            m[s.top()] = n;
            s.pop();
         }
         s.push(n);
      }
      for (int i = 0; i < n; i++) {
         if (m.count(nums1[i])) ans[i] = m[nums1[i]];
      }
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}
