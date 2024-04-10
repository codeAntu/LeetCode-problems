
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> s;

    for (auto& c : tokens) {
      if (c == "+" || c == "-" || c == "*" || c == "/") {
        int b = s.top();
        s.pop();
        int a = s.top();
        s.pop();
        if (c == "+")
          s.push(a + b);
        else if (c == "-")
          s.push(a - b);
        else if (c == "*")
          s.push(a * b);
        else if (c == "/")
          s.push(a / b);
      } else {
        s.push(stoi(c));
      }
    }
    return s.top();
  }
};

int main() {
  Solution s;

  return 0;
}