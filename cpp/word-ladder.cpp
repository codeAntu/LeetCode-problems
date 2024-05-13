#include <queue>
#include <string>
#include <unordered_map>
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, vector<string>> dict;
    unordered_map<string, bool> visited;
    queue<string> q;
    int level = 0;
    for (auto word : wordList) {
      for (int i = 0; i < word.size(); i++) {
        string key = word.substr(0, i) + "*" + word.substr(i + 1);
        dict[key].push_back(word);
      }
    }

    q.push(beginWord);
    visited[beginWord] = true;  

    while (!q.empty()) {
      int size = q.size();
      level++;
      for (int i = 0; i < size; i++) {
        string word = q.front();
        q.pop();
        for (int i = 0; i < word.size(); i++) {
          string key = word.substr(0, i) + "*" + word.substr(i + 1);
          for (auto w : dict[key]) {
            if (w == endWord) {
              return level + 1;
            }
            if (!visited[w]) {
              visited[w] = true;
              q.push(w);
            }
          }
        }
      }
    }

    return 0;
  }
};

int main() {
  Solution s;

  return 0;
}