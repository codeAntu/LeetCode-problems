#include <set>
#include <unordered_map>
#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> res(arr.size());
    unordered_map<int, int> rankMap;
    set<int> sorted(arr.begin(), arr.end());

    int rank = 1;
    for (const int& num : sorted) {
      rankMap[num] = rank++;
    }

    for (int i = 0; i < arr.size(); i++) {
      res[i] = rankMap[arr[i]];
    }

    return res;
  }
};

int main() {
  Solution s;

  return 0;
}