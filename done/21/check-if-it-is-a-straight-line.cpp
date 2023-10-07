#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   bool checkStraightLine(vector<vector<int>>& coordinates) {
      int n = coordinates.size();
      int dy = coordinates[0][0] - coordinates[1][0];
      int dx = coordinates[0][1] - coordinates[1][1];
      for (int i = 0; i < n - 1; i++)
      {
         int cdy = coordinates[i][0] - coordinates[i + 1][0];
         int cdx = coordinates[i][1] - coordinates[i + 1][1];
         if (dy * cdx != dx * cdy)
            return false;
      }
      return true;
   }
};


int main() {
   Solution s;


   return 0;
}