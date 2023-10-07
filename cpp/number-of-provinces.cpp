#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   void dfs(int x, int n, vector<bool>& visited, vector<vector<int>>& isConnected) {
      visited[x] = true;
      for (int i = 0; i < n; i++) {
         if (isConnected[x][i] && !visited[i]) {
            dfs(i, n, visited, isConnected);
         }
      }
   }
   int findCircleNum(vector<vector<int>>& isConnected) {
      int n = isConnected.size();
      vector<bool> visited(n, false);
      int count = 0;
      for (int i = 0;i < n; i++) {
         if (!visited[i]) {
            dfs(i, n, visited, isConnected);
            count++;
         }
      }
      return count;
   }
};

int main() {
   Solution s;


   return 0;
}