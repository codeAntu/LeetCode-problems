#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;



class Solution {
public:
   bool isRobotBounded(string instructions) {
      int direc[4] = { 0 };
      int currind = 0;
      int len = instructions.length();

      for (char c : instructions) {
         if (c == 'G')
            direc[currind]++;
         else if (c == 'L')
         {
            if (currind == 0) currind = 3;
            else currind--;
         } else if (c == 'R')
         {
            if (currind == 3) currind = 0;
            else currind++;
         }
      }
      if (direc[0] == direc[2] && direc[1] == direc[3]) return true;
      if (currind == 0) return false;
      return true;
   }
};

int main() {
   Solution s;
   std::cout << s.isRobotBounded("GGLLGG");


   return 0;
}