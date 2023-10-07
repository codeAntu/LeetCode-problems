#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include "algorithm"
using namespace std;

class Solution {
public:
   int minimumSum(int num) {
      vector<int> arr(4);
      int res;
      for (int i = 0; i < 4; i++) {
         arr[i] = num % 10;
         num /= 10;
      };
      sort(arr.begin(), arr.end());
      for (int i = 0; i < 4; i++) {
         cout << arr[i];
      }
      return arr[0] * 10 + arr[1] * 10 + arr[2] + arr[3];
   }
};

int main() {
   Solution s;

   cout << s.minimumSum(2932);

   return 0;
}