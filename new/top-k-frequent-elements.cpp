

#include <algorithm>

#include "iostream"
#include "map"
#include "math.h"
#include "unordered_map"
#include "vector"

using namespace std;

class Solution {
  public:
   vector<int> topKFrequent(vector<int>& nums, int k) {
      vector<int> res;
      unordered_map<int, int> m;

      for (int num : nums) {
         m[num]++;
      }

      vector<pair<int, int>> elements(m.begin(), m.end());

      sort(elements.begin(), elements.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
         return a.second > b.second;
      });

      for (int i = 0; i < k && i < elements.size(); ++i) {
         res.push_back(elements[i].first);
      }

      return res;
   }
};

int main() {
   Solution s;

   return 0;
}
