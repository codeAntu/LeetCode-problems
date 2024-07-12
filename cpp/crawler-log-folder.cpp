
#include "string"
#include "vector"
using namespace std;

class Solution {
public:
  int minOperations(vector<string>& logs) {
    int n = 0;

    for (int i = 0; i < logs.size(); i++) {
      if (logs[i] == "../") {
        if (n > 0) {
          n--;
        }
      } else if (logs[i] == "./") {
        continue;
      } else {
        n++;
      }
    }
    return n;
  }
};

int main() {
  Solution s;

  return 0;
}