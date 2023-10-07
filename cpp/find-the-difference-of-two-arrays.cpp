#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include "unordered_set"
using namespace std;

class Solution {
public:
   vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
      unordered_set<int> s1(nums1.begin(), nums1.end());
      unordered_set<int> s2(nums2.begin(), nums2.end());
      vector<vector<int>> ans(2);
      
      for (int n : s1) {
         if (s2.find(n) == s2.end()) ans[0].push_back(n);
      }
      for (int n : s2) {
         if (s1.find(n) == s1.end()) ans[1].push_back(n);
      }
      return ans;
   }
};

int main() {
   Solution s;


   return 0;
}