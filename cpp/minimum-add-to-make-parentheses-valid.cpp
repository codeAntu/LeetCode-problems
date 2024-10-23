#include <stack>
#include "math.h"
#include "string"


using namespace std;

class Solution {
public:
  int minAddToMakeValid(string s) {
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        st.push(s[i]);
      } else {
        if (!st.empty() && st.top() == '(') {
          st.pop();
        } else {
          st.push(s[i]);
        }
      }
    }

    return st.size();
  }
};

int main() {
  Solution s;

  return 0;
}