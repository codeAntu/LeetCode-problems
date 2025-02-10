#include "iostream"
using namespace std;

class Solution {
public:
  string clearDigits(string s) {
    string result = "";
    for (char c : s) {
      if (isdigit(c)) {
        result.pop_back();
      } else {
        result.push_back(c);
      }
    }
    return result;
  }
};

int main() {
  Solution s;

  return 0;
}
