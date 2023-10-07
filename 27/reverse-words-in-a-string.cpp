#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   string reverseWords(string s) {
      int len = s.length(), i, j ;\
      bool a = false;
      string newstr = "";

      for (i = len - 1; i >= 0; i--) {
         for (j = i; j >= 0; j--) {
            if (s[j] == ' ') {
               break;
            }
         }
         if (a && i != j) newstr += ' ';
         newstr += s.substr(j + 1, j -i);
         if (i != j) a = true;
         i = j;
      }
      return newstr;
   }
};

int main() {
   Solution s;


   return 0;
}