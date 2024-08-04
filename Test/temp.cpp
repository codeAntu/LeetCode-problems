#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void preComputeMaxMin(const vector<vector<int>>& grid, vector<vector<int>>& maxGrid,
                      vector<vector<int>>& minGrid, int N) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int maxVal = grid[i][j], minVal = grid[i][j];
      if (i > 0) {
        maxVal = max(maxVal, maxGrid[i - 1][j]);
        minVal = min(minVal, minGrid[i - 1][j]);
      }
      if (j > 0) {
        maxVal = max(maxVal, maxGrid[i][j - 1]);
        minVal = min(minVal, minGrid[i][j - 1]);
      }
      if (i > 0 && j > 0) {
        maxVal = max(maxVal, maxGrid[i - 1][j - 1]);
        minVal = min(minVal, minGrid[i - 1][j - 1]);
      }
      maxGrid[i][j] = maxVal;
      minGrid[i][j] = minVal;
    }
  }
}

int findMaxSumOfBeauties(const vector<vector<int>>& grid, int N) {
  if (N == 2) return 0;
  vector<vector<int>> maxGrid(N, vector<int>(N, 0)), minGrid(N, vector<int>(N, INT_MAX));
  preComputeMaxMin(grid, maxGrid, minGrid, N);
  int maxBeautySum = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int beauty = maxGrid[i][j] - minGrid[i][j];

      maxBeautySum = max(maxBeautySum, beauty);
    }
  }

  return maxBeautySum;
}

int main() {
  int N;
  cout << "Enter the size of the grid (N): ";
  cin >> N;
  vector<vector<int>> grid(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> grid[i][j];
    }
  }

  int maxBeautySum = findMaxSumOfBeauties(grid, N);
  cout << "Maximum sum of beauties: " << maxBeautySum << endl;

  return 0;
}
