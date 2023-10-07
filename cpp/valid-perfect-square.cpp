#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

// class Solution {
// public:
//    bool isPerfectSquare(int num) {
//       int i = 1;
//       while (num > 0){
//          num -= i;
//          i += 2;
//       }
//       return num == 0 ? true : false;
//    }
// };

class Solution {
public:
   bool isPerfectSquare(int num) {
      int low = 1, high = num, mid;
      while (low <= high) {
         mid = (low + high) / 2;
         if (mid * mid == num) return true;
         if (mid * mid > num) high = mid;
         if (mid * mid < num) low = mid + 1;
      }
      return false;
   }
};

int main() {
   Solution s;


   return 0;
}