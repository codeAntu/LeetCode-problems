#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int minPartitions(string n) {
      int max = 0;
      for (char c : n) {
         if (max < c - '0') max = c - '0';
      }
      return max;
   }
};

int main() {
   Solution s;


   return 0;
}