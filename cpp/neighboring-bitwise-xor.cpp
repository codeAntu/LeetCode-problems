#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  bool doesValidArrayExist(vector<int>& derived) {
    bool first = false;
    bool last = false;
    for (int x : derived) {
      if (x) last = !last;
    }
    return first == last;
  }
};

int main() {
  Solution s;

  return 0;
}