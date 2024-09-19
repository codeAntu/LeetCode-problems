#include "string"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  vector<int> diffWaysToCompute(string expression) {
    vector<int> res;

    for (int i = 0; i < expression.size(); ++i) {
      char oper = expression[i];

      if (oper == '+' || oper == '*' || oper == '-') {
        vector<int> nums1 = diffWaysToCompute(expression.substr(0, i));
        vector<int> nums2 = diffWaysToCompute(expression.substr(i + 1));

        for (auto num1 : nums1) {
          for (auto num2 : nums2) {
            if (oper == '+')
              res.push_back(num1 + num2);
            else if (oper == '-')
              res.push_back(num1 - num2);
            else if (oper == '*')
              res.push_back(num1 * num2);
          }
        }
      }
    }

    if (res.empty()) res.push_back(stoi(expression));
    return res;
  }
};

int main() {
  Solution s;

  return 0;
}