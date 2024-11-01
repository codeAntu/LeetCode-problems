#include "string"

using namespace std;

class Solution {
public:
  string makeFancyString(string s) {
    string res = "";
    int count = 1;
    res += s[0];
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == s[i - 1]) {
        count++;
      } else {
        count = 1;
      }
      if (count < 3) {
        res += s[i];
      }
    }
    return res;
  }
};

int main() {
  Solution s;

  return 0;
}