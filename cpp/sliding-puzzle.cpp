#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  vector<vector<char>> moves = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
  int slidingPuzzle(vector<vector<int>>& board) {
    string target = "123450";
    string start = "";
    int pos = -1;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        start += to_string(board[i][j]);
        if (board[i][j] == 0) {
          pos = i * 3 + j;
        }
      }
    }

    if (start == target) {
      return 0;
    }

    unordered_set<string> visited;
    visited.reserve(720);
    queue<pair<string, int>> q;

    q.push({start, pos});

    int step = 0;

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        auto [cur, pos] = q.front();
        q.pop();

        if (cur == target) {
          return step;
        }

        for (auto next_pos : moves[pos]) {
          string next = cur;
          swap(next[pos], next[next_pos]);
          if (visited.find(next) == visited.end()) {
            visited.insert(next);
            q.push({next, next_pos});
          }
        }
      }
      step++;
    }

    return -1;
  }
};

int main() {
  Solution s;

  return 0;
}