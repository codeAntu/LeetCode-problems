#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
  int countSegments(string s) {
    int count = 0;
    bool isNew = true;

    for (char c : s) {
      if (c != ' ' && isNew) {
        count++;
        isNew = false;
      } else if (c == ' ') {
        isNew = true;
      }
    }
    return count;
  }
};

int main() {
  Solution s;


  return 0;
}
