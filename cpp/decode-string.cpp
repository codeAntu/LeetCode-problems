#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include "stack"
using namespace std;

class Solution {
public:
   string decodeString(string s) {
      stack<char> stk;
      for (char ch : s) {
         if (ch != ']') stk.push(ch);
         else {
            string temp = "";
            while (stk.top() != '[') {
               temp = stk.top() + temp;
               stk.pop();
            }
            stk.pop();
            string num = "";
            while (!stk.empty() && isdigit(stk.top())) {
               num = stk.top() + num;
               stk.pop();
            }
            int n = stoi(num);
            while (n--) {
               for (char c : temp) {
                  stk.push(c);
               }
            }
         }
      }
      string ans = "";
      while (!stk.empty()) {
         ans = stk.top() + ans;
         stk.pop();
      }
      return ans;

   }
};

int main() {
   Solution s;


   return 0;
}