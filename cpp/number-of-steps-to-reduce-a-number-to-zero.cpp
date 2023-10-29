#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

class Solution {
  public:
   int numberOfSteps(int num) {
      int count = 0;
      while (num) {
         if (num % 2 == 1) {
            num--;
            count++;
            continue;
         }

         num = num / 2;
         count++;
      }
      return count;
   }
};

int main() {
   Solution s;

   return 0;
}
