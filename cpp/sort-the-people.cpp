#include <algorithm>
#include <unordered_map>
#include "string"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    unordered_map<int, int> heightMap;
    vector<string> result;

    for (int i = 0; i < heights.size(); i++) {
      heightMap[heights[i]] = i;
    }
    sort(heights.begin(), heights.end(), greater<int>());
    for (int i = 0; i < heights.size(); i++) {
      result.push_back(names[heightMap[heights[i]]]);
    }

    return result;
  }
};

int main() {
  Solution s;

  return 0;
}