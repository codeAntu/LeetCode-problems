#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;
// The API isBadVersion is defined for you.
bool isBadVersion(int version) {
   return 0;
}


class Solution {
public:
   int firstBadVersion(int n) {

      int low = 0, high = n, mid;

      while (low < high)
      {
         mid = low + (high - low) / 2;

         if (isBadVersion(mid)) {
            high = mid;
         } else {
            low = mid + 1;
         }
      }
      return low;
   }

};


int main() {
   Solution s;


   return 0;
}