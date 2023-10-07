#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int smallestEvenMultiple(int n) {
      return n & 1 ? n * 2 : n;
   }
};

int main() {
   Solution s;


   return 0;
}