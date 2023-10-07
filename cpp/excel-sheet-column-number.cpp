#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int titleToNumber(string columnTitle) {
      int num = 0;

      for (int i = 0; i < columnTitle.length(); i++)
         num *= 26 + columnTitle[i] - 'A' + 1;
      return num;
   }
};

int main() {
   Solution s;


   return 0;
}
