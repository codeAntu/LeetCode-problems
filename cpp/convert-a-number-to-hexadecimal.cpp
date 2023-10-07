#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   string toHex(int num) {
      if (num == 0) return "0";
      string s;
      char arr[] = "0123456789abcdef";
      unsigned int n = num;
      if (n < 0) n *= -1;
      while (n) {
         s = arr[n % 16] + s;
         n = n / 16;
      }
      return s;
   }
};

int main() {
   Solution s;

   unsigned int x = -1;
   cout << x;

   return 0;
}