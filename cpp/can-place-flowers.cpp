#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      int len = flowerbed.size();
      if (n == 0) return true;
      if (len == 1 && n == 1) return !flowerbed[0];
      if (len == 1 && n > 1) return false;

      if (!flowerbed[0] && !flowerbed[1]) {
         n--;
         flowerbed[0] = 1;
      }
      if (n == 0) return true;
      for (int i = 1; i < len - 1; i++) {
         if (!flowerbed[i] && !flowerbed[i + 1] && !flowerbed[i - 1]) {
            n--;
            flowerbed[i] = 1;
         }
         if (n == 0) return true;
      }
      if (!flowerbed[len - 1] && !flowerbed[len - 2]) {
         n--;
         flowerbed[len - 1] = 1;
      }
      if (n == 0) return true;
      return false;
   }
};

int main() {
   Solution s;
   vector<int> arr = { 0,0,1,0,1 };

   cout << s.canPlaceFlowers(arr, 1);

   return 0;
}