#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int equalPairs(vector<vector<int>>& grid) {
      map<vector<int>, int> mp;
      int ans = 0;
      for (int i = 0; i < grid.size(); i++) {
         mp[grid[i]]++;
      }
      for (int i = 0; i < grid[0].size(); i++)
      {
         vector<int> temp;
         for (int j = 0; j < grid.size(); j++)
         {
            temp.push_back(grid[j][i]);
         }
         ans += mp[temp];
      }
      return ans;
   }
};


int main() {
   Solution s;


   return 0;
}