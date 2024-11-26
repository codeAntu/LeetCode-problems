#include "vector"

using namespace std;

class Solution {
public:
  int findChampion(int n, vector<vector<int>>& edges) {
    vector<int> inDegree(n, 0);

    for (auto edge : edges) {
      inDegree[edge[1]]++;
    }

    int res = -1;

    for (int i = 0; i < n; i++) {
      if (inDegree[i] == 0) {
        if (res != -1) {
          return -1;
        }
        res = i;
      }
    }

    return res;
  }
};

int main() {
  Solution s;

  return 0;
}