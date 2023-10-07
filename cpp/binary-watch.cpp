#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int countBit(int x) {
      int count = 0;
      while (x) {
         if (x & 1) count++;
         x >>= 1;
      }
      return count;
   }
   vector<string> readBinaryWatch(int turnedOn) {
      vector<string> res;
      for (int h = 0; h < 12;h++) {
         for (int m = 0; m < 60; m++) {
            if (countBit(h) + countBit(m) == turnedOn) {
               res.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
            }
         }
      }
      return res;
   }
};

int main() {
   Solution s;
   // cout << s.countBit(0) + s.countBit(1);
   s.readBinaryWatch(2);
   return 0;
}