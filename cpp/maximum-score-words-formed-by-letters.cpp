#include <string>
#include <unordered_map>
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  unordered_map<char, int> letterCount;
  int arr[26] = {0};

  bool canForm(string word) {
    bool flag = true;
    for (char c : word) {
      arr[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
      if (arr[i] > letterCount[i + 'a']) {
        flag = false;
      }
      arr[i] = 0;
    }

    return flag;
  }

  int dfs(vector<string>& words, vector<int>& scores, int i) {
    if (i == words.size()) {
      return 0;
    }
    int res = dfs(words, scores, i + 1);
    int score = 0;
    if (canForm(words[i])) {
      for (char c : words[i]) {
        score += scores[c - 'a'];
        letterCount[c]--;
      }
      res = max(res, score + dfs(words, scores, i + 1));
      for (char c : words[i]) {
        letterCount[c]++;
      }
    }
    return res;
  }
  int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    for (char c : letters) {
      letterCount[c]++;
    }
    vector<int> scores(26, 0);
    for (int i = 0; i < 26; i++) {
      scores[i] = score[i];
    }
    return dfs(words, scores, 0);
  }
};

int main() {
  Solution s;

  return 0;
}