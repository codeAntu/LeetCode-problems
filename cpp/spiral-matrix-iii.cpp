#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    int direction[5] = {0, 1, 0, -1, 0};
    vector<vector<int>> result;
    result.push_back({rStart, cStart});
    int r = rStart, c = cStart;
    int n = 0;
    int i = 0;

    while (result.size() < rows * cols) {
      for (int j = 0; j < n / 2 + 1; j++) {
        r += direction[i];
        c += direction[i + 1];
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
          result.push_back({r, c});
        }
      }
      n++;
      i = (i + 1) % 4;
    }

    return result;
  }
};

// class Solution {
// public:
//     vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
//         int directions[5] = {0, 1, 0, -1, 0};
//         vector<vector<int>> res = {{rStart, cStart}};
//         int j = 0, n = 0;
//         while (res.size() != rows * cols){
//             for (int i = 0; i < n / 2 + 1; i++){
//                 rStart += directions[j], cStart += directions[j+1];
//                 if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
//                     res.push_back({rStart, cStart});
//             }
//             n++;
//             j = (j + 1) % 4;
//         }
//         return res;
//     }
// };

int main() {
  Solution s;

  return 0;
}
