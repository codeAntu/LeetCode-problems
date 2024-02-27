#include <string>

#include "math.h"

using namespace std;

class Solution {
 public:
   bool checkRecord(string s) {
      int a = 0;
      int l = 0;

      for (int i = 0; i < s.length(); i++) {
         if (s[i] == 'A') {
            a++;
            l = 0;
            if (a > 1) {
               return false;
            }
         } else if (s[i] == 'L') {
            l++;
            if (l > 2) {
               return false;
            }
         } else {
            l = 0;
         }
      }
      return true;
   }
};

int main() {
   Solution s;

   return 0;
}