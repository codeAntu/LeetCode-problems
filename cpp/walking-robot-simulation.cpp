#include <utility>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    map<pair<int, int>, bool> obstacleMap;

    for (auto obstacle : obstacles) {
      obstacleMap[make_pair(obstacle[0], obstacle[1])] = true;
    }

    int x = 0, y = 0, direction = 0, maxDistance = 0;

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (int command : commands) {
      if (command == -1) {
        direction = (direction + 1) % 4;
      } else if (command == -2) {
        direction = (direction + 3) % 4;
      } else {
        for (int i = 0; i < command; i++) {
          int nextX = x + directions[direction].first;
          int nextY = y + directions[direction].second;

          if (obstacleMap.find(make_pair(nextX, nextY)) != obstacleMap.end()) {
            break;
          }

          x = nextX;
          y = nextY;
          maxDistance = max(maxDistance, x * x + y * y);
        }
      }
    }

    return maxDistance;
  }
};

int main() {
  Solution s;
  vector<int> commands = {4, -1, 3};
  vector<vector<int>> obstacles = {{2, 4}};

  cout << s.robotSim(commands, obstacles) << endl;

  return 0;
}