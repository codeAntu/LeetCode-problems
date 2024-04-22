#include <string>

#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int openLock(vector<string>& deadends, string target) {
    vector<bool> visited(10000, false);
    for (string deadend : deadends) {
      visited[stoi(deadend)] = true;
    }

    if (visited[0]) {
      return -1;
    }

    vector<int> directions = {1, -1};
    vector<int> queue = {0};
    visited[0] = true;
    int steps = 0;

    while (!queue.empty()) {
      vector<int> next;
      for (int current : queue) {
        if (current == stoi(target)) {
          return steps;
        }

        for (int i = 0; i < 4; i++) {
          for (int direction : directions) {
            int nextCombination = (current / (int)pow(10, i) % 10 + direction + 10) % 10;
            int nextNumber =
                current + (nextCombination - (current / (int)pow(10, i) % 10)) * (int)pow(10, i);
            if (!visited[nextNumber]) {
              visited[nextNumber] = true;
              next.push_back(nextNumber);
            }
          }
        }
      }
      queue = next;
      steps++;
    }

    return -1;
  }
};

int main() {
  Solution s;

  return 0;
}