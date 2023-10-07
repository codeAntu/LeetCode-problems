#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   bool judgeCircle(string moves) {
      int r = 0, u = 0;
      int n = moves.length();
      for (int i = 0; i < n; i++)
      {
         if (moves[i] == 'R') r++;
         if (moves[i] == 'L') r--;
         if(moves[i] == 'U') u++;
         if(moves[i] == 'D') u--;

      }
   return  r == 0 && u == 0 ? true : false;
   }
};

int main() {
   Solution s;


   return 0;
}