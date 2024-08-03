#include <unordered_map>

#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  bool canBeEqual(vector<int>& target, vector<int>& arr) {
    unordered_map<int, int> m;

    for (int i = 0; i < target.size(); i++) {
      m[target[i]]++;
      m[arr[i]]--;
    }

    for (auto it = m.begin(); it != m.end(); it++) {
      if (it->second != 0) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  Solution s;

  return 0;
}