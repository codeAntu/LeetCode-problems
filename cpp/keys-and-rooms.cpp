#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int room) {
      for (int i = 0; i < rooms[room].size(); i++) {
         if (!visited[rooms[room][i]]) {
            visited[rooms[room][i]] = true;
            dfs(rooms, visited, rooms[room][i]);
         }
      }
   }

   bool canVisitAllRooms(vector<vector<int>>& rooms) {
      vector<bool> visited(rooms.size(), false);
      visited[0] = true;
      dfs(rooms, visited, 0);
      for (int i = 0; i < visited.size(); i++) {
         if (!visited[i]) return false;
      }
      return true;
   }
};


int main() {
   Solution s;


   return 0;
}