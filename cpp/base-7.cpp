#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

class Solution {
  public:
   string convertToBase7(int num) {
      if (num == 0) {
         return "0";
      }
      string ans = "";
      bool neg = false;
      if (num < 0) {
         neg = true;
         num = -num;
      }
      while (num > 0) {
         ans = to_string(num % 7) + ans;
         num /= 7;
      }
      if (neg) {
         ans = "-" + ans;
      }
      return ans;
   }
};

int main() {
   return 0;
}
