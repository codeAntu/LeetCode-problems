#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int diagonalSum(vector<vector<int>>& mat) {
      int len = mat.size(), sum = 0;
      for (int i = 0; i < len; i++)
      {
         sum += mat[i][i];
         sum += mat[i][len - i - 1];
      }

      return len & 1 ? sum - mat[len / 2][len / 2] : sum;
   }
};

int main() {
   Solution s;


   return 0;
}