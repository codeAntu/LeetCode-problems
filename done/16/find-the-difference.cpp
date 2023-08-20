#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;


class Solution {
public:
   char findTheDifference(string s, string t) {
      char c = 0;
      for (char c1 : s) c ^= c1;
      for (char c2 : t) c ^= c2;

      return c;
   }
};



int main() {
   Solution s;


   return 0;
}