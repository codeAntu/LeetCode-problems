#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include "list"
#include "set"
#include "unordered_set"

using namespace std;

// class Solution {
// public:
//    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
//       set<int> x;
//       int ans = 0;
//       for (int i = 0; i < points.size(); i++) 
//          x.insert(points[i][0]);
//       for (auto it = next(x.begin()); it != x.end(); it++) 
//          ans = max(ans, *it - *prev(it));
//       return ans;
//    }
// };

class Solution {
public:
   int maxWidthOfVerticalArea(vector<vector<int>>& points) {
      vector<int > x;
      int ans = 0;
      for (int i = 0; i < points.size(); i++)
         x.push_back(points[i][0]);
      sort(x.begin(), x.end());
      for (int i = 1; i < x.size(); i++)
         ans = max(ans, x[i] - x[i - 1]);
      return ans;
   }
};






int main() {
   Solution s;

   s.maxWidthOfVerticalArea({ [8,7] ,[9,9],[7,4],[9,7] })
      return 0;
}