#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int finalValueAfterOperations(vector<string>& operations) {
      int x = 0;
      for (auto op : operations) {
         if ((op[0] == '+' && op[1] == '+') || (op[1] == '+' && op[2] == '+')) x++;
         else x--;
      }
      return x;
   }
};


int main() {
   Solution s;


   return 0;
}