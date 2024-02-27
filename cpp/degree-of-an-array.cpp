#include <unordered_map>
#include <utility>
#include "math.h"
#include "vector"


using namespace std;

class Solution {
 public:
   int findShortestSubArray(vector<int> &nums) {
      unordered_map<int, pair<int, int>> m;
      int minLen = 0;
      int maxFreq = 0;

      for (int i = 0; i < nums.size(); i++) {
         m[nums[i]].first++;
         if (m[nums[i]].first == 1) {
            m[nums[i]].second = i;
         }
         if (m[nums[i]].first > maxFreq) {
            maxFreq = m[nums[i]].first;
            minLen = i - m[nums[i]].second + 1;
         } else if (m[nums[i]].first == maxFreq) {
            minLen = min(minLen, i - m[nums[i]].second + 1);
         }
      }
      return minLen;
   }
};

int main() {
   Solution s;

   return 0;
}
