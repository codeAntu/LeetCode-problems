#include "string"

using namespace std;

class Solution {
public:
  bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) {
      return false;
    }

    if (s == goal) {
      return true;
    }

    for (int i = 0; i < s.size(); i++) {
      if (s.substr(i) + s.substr(0, i) == goal) {
        return true;
      }
    }

    return false;
  }
};

int main() {
  Solution s;

  return 0;
}