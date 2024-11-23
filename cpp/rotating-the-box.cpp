#include "vector"

using namespace std;

class Solution {
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int row = box.size();
    int col = box[0].size();

    vector<vector<char>> res(col, vector<char>(row, '.'));

    for (int i = 0; i < row; i++) {
      int last = col - 1;
      for (int j = col - 1; j >= 0; j--) {
        if (box[i][j] == '*') {
          res[j][row - i - 1] = '*';
          last = j - 1;
        } else if (box[i][j] == '#') {
          res[last][row - i - 1] = '#';
          last--;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;

  return 0;
}