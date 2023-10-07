#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int numJewelsInStones(string jewels, string stones) {
      int arr[52] = { 0 };
      int count = 0;

      for (int i = 0;i < jewels.length();i++) {
         if (jewels[i] >= 'a' && jewels[i] <= 'z') arr[jewels[i] - 'a'] = 1;
         else arr[jewels[i] - 'A' + 26] = 1;
      }

      for (int i = 0; i < stones.length(); i++) {
         if(stones[i] >= 'a' && stones[i] <= 'z') count += arr[stones[i] - 'a'];
         else count += arr[stones[i] - 'A' + 26];
      }
      return count;
   }
};

int main() {
   Solution s;


   return 0;
}