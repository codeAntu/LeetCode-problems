#include <unordered_map>
#include <utility>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>


using namespace std;

class Solution {
public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    unordered_map<int, pair<int, int>> num;
    int rows = mat.size();
    int cols = mat[0].size();
    vector<int> row(rows, 0), col(cols, 0);

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        num[mat[i][j]] = {i, j};
      }
    }

    for (int i = 0; i < arr.size(); i++) {
      pair<int, int> p = num[arr[i]];

      row[p.first]++;
      col[p.second]++;

      if (row[p.first] == cols || col[p.second] == rows) {
        return i;
      }
    }

    return -1;
  }
};

int main() {
  Solution s;

  vector<int> arr = {1, 2, 3};
  vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  cout << s.firstCompleteIndex(arr, mat) << endl;

  return 0;
}