#include <algorithm>
#include <iostream>
#include <queue>

#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    int n = deck.size();
    vector<int> res(n);
    queue<int> q;
    sort(deck.begin(), deck.end());

    for (int i = 0; i < n; i++) {
      q.push(i);
    }

    for (int i = 0; i < n; i++) {
      if (i) {
        q.push(q.front());
        q.pop();
      }
      res[q.front()] = deck[i];
      q.pop();
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
  vector<int> res = s.deckRevealedIncreasing(deck);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;

  return 0;
}