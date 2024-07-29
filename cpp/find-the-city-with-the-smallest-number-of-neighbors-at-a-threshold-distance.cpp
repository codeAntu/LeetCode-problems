#include "math.h"
#include "vector"
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; ++i) dist[i][i] = 0;
        for (auto& edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int min_neigh = n, res = -1;
        for (int i = 0; i < n; ++i) {
            int neigh = 0;
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] <= distanceThreshold) ++neigh;
            }
            if (neigh <= min_neigh) {
                min_neigh = neigh;
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