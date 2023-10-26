#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
  string addStrings(string num1, string num2) {
    int n = num1.size() - 1, m = num2.size() - 1, carry = 0;

    string res = "";

    while (n >= 0 && m >= 0) {
      int sum = (num1[n] - '0') + (num2[m] - '0') + carry;
      carry = sum / 10;
      res = to_string(sum % 10) + res;
      n--;
      m--;
    }
    while (n >= 0) {
      int sum = (num1[n] - '0') + carry;
      carry = sum / 10;
      res = to_string(sum % 10) + res;
      n--;
    }
    while (m >= 0) {
      int sum = (num2[m] - '0') + carry;
      carry = sum / 10;
      res = to_string(sum % 10) + res;
      m--;
    }

    return carry == 1 ? "1" + res : res;

  }
};

int main() {
  Solution s;


  return 0;
}
