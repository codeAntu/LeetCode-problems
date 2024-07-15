#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++) {
      for (int j = i; j < n - i - 1; j++) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[n - j - 1][i];
        matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
        matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
        matrix[j][n - i - 1] = temp;
      }
    }
  }
};

// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int row = matrix.size();
//         for(int i=0;i<row; i++){
//             for(int j=0; j<=i;j++){
//                 swap(matrix[i][j], matrix[j][i]);
//             }
//         }
//         for(int i=0;i<row;i++){
//             reverse(matrix[i].begin(), matrix[i].end());
//         }
//     }
// };

int main() {
  Solution s;

  return 0;
}