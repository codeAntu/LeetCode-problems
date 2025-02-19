#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  string getHappyString(int n, int k) {
    int total = pow(2, n - 1) * 3;

    if (k > total) {
      return "";
    }
    int left = 1, right = total;
    string res = "";
    string chars = "abc";

    for (int i = 0; i < n; i++) {
      int curr = left;
      int part = (right - left + 1) / chars.size(); // Corrected line

      for (char c : chars) {
        if (curr <= k && k < curr + part) {
          string temp = "abc";
          res += c;
          left = curr;
          right = curr + part - 1;
          chars = temp.erase(temp.find(c), 1);
          break;
        }
        curr += part;
      }
    }

    return res;
  }
};

int main() {
  Solution s;

  return 0;
}