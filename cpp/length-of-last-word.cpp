#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;
class Solution {
public:
   int lengthOfLastWord(string s) {
      int  count = 0;
      int i = s.length() - 1;
      while (i >= 0 && s[i] == ' ') i--;
      while (i >= 0 && s[i] != ' ') count++,i--;
      return count;
   }
};


class Solution {
public:
   int lengthOfLastWord(string s) {
      int  count = 0;
      for (int i = s.length() - 1; i >= 0; i--)
      {
         if (count == 0 && s[i] == ' ') continue;
         if (s[i] == ' ') return count;
         count++;
      }
      return count;

   }
};

int main() {
   Solution s;


   return 0;
}
