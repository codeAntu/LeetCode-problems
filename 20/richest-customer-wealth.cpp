#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int maximumWealth(vector<vector<int>>& accounts) {
      int sum = 0, max = 0;
      for (vector<int>& customer : accounts) {
         sum = 0;
         for (int money : customer) {
            sum+= money;
         }
         if(sum > max) max = sum;
      }
      return max;
   }
};

int main() {
   Solution s;


   return 0;
}