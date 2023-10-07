#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;
class Solution {
public:
   vector<int> spiralOrder(vector<vector<int>>& matrix) {
      int u = 0, b = matrix.size(), l = 0, r = matrix[0].size();
      vector<int> arr;
      while (r > l && b > u)
      {
         for (int i = l; i < r && b> u; i++)
         {
            arr.push_back(matrix[u][i]);
         }
         u++;
         for (int i = u; i < b && r > l; i++)
         {
            arr.push_back(matrix[i][r - 1]);
         }
         r--;
         for (int i = r; i > l && b > u; i--)
         {
            arr.push_back(matrix[b - 1][i - 1]);
         }
         b--;
         for (int i = b; i > u && r > l; i--)
         {
            arr.push_back(matrix[i - 1][l]);
         }
         l++;
      }
      return arr;
   }
};

int main() {
   Solution s;


   return 0;
}