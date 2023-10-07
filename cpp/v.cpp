#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   double average(vector<int>& salary) {
      int max = salary[0], min = salary[0], sum = 0;
      for (int money : salary)
      {
         sum += money;
         if (money > max) max = money;
         if (min > money) min = money;
      }

      return (sum - max - min) * 1.0 / (salary.size()-2);
   }
};

int main() {
   Solution s;


   return 0;
}