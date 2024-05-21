#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include "math.h"
#include "vector"

using namespace std;

// greater BY COPILOT 

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        vector<string> itinerary;
        
        for(auto& ticket : tickets)
            graph[ticket[0]].push(ticket[1]);
        
        dfs(graph, "JFK", itinerary);
        reverse(itinerary.begin(), itinerary.end());
        
        return itinerary;
    }
    
private:
    void dfs(unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph, string airport, vector<string>& itinerary) {
        while(!graph[airport].empty()) {
            string nextAirport = graph[airport].top();
            graph[airport].pop();
            dfs(graph, nextAirport, itinerary);
        }
        itinerary.push_back(airport);
    }
};







// THIS WILL WORK BUT TIME LIMIT EXCEEDED

// class Solution {
// public:
//   vector<string> res;
//   int n;
//   bool dfs(unordered_map<string, vector<string>>& graph, string start) {
//     res.push_back(start);

//     if (res.size() == n + 1) {
//       return true;
//     }

//     int size = graph[start].size();

//     if(size == 0) {
//       res.pop_back();
//       return false;
//     }

//     for (int i = 0; i < size; i++) {
//       string next = graph[start][i];
//       graph[start].erase(graph[start].begin() + i);
//       if (dfs(graph, next)) {
//         return true;
//       }
//       graph[start].insert(graph[start].begin() + i, next);
//     }

//     res.pop_back();
//     return false;
//   }

//   vector<string> findItinerary(vector<vector<string>>& tickets) {
//     sort(tickets.begin(), tickets.end());
//     unordered_map<string, vector<string>> graph;
//     n = tickets.size();

//     for (auto ticket : tickets) {
//       graph[ticket[0]].push_back(ticket[1]);
//     }

//     dfs(graph, "JFK");

//     return res;
//   }
// };

int main() {
  Solution s;

  return 0;
}