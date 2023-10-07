#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;
// done

class Solution {
public:
   int mySqrt(int x) {
      int high = x / 2 + 1, low = 0 ;
      long mid;
      
      while (high >= low)
      {
         mid = (high + low) / 2;
         cout << mid << endl;
         if (mid * mid == x)
            return mid;
         else if (mid * mid > x)
            high = mid - 1;
         else
            low = mid + 1 ;  
      }
   return high;
   }
};

int main() {
   Solution s;

   cout << s.mySqrt(8);

   return 0;
}