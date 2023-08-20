#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int hammingWeight(uint32_t n) {
      int count = 0;
      for (int i = 0; i < 32; i++)
      {
         if ((n >> i) & 1)
            count++;
      }
      return count;
   }
};

int main() {
   Solution s;


   return 0;
}