#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   bool lemonadeChange(vector<int>& bills) {
      int count5 = 0, count10 = 0;
      for (int pay : bills) {
         if (pay == 5) count5++;
         if (pay == 10) {
            count10++;
            if (count5) count5--;
            else return false;
         }
         if (pay == 20) {
            if (count10) {
               count10--;
               if (count5) count5--;
               else return false;
            } else {
               if (count5 < 3) return false;
               else count5 -= 3;
            }
         }
      }
      return true;
   }
};

int main() {
   Solution s;


   return 0;
}