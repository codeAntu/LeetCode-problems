#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

class Solution {
  public:
   vector<int> constructRectangle(int area) {
      int x = sqrt(area);
      while (area % x != 0) {
         x--;
      }
      return {area / x, x};
   }
};

class Solution {
  public:
   vector<int> constructRectangle(int area) {
      return {int(area / sqrt(area)), int(sqrt(area))};
   }
};

int main() {
   Solution s;

   return 0;
}
