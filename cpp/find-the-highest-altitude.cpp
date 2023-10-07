#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int largestAltitude(vector<int>& gain) {
      int sum = 0, res = 0;
      for (int i = 0; i < gain.size(); i++) {
         sum += gain[i];
         res = max(res, sum);
      }
      return res;
   }
};

int main() {
   Solution s;


   return 0;
}