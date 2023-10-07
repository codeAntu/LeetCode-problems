#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   vector<double> convertTemperature(double celsius) {
      return {celsius + 273.15 , celsius * 1.80 + 32.00};
   }
};

int main() {
   Solution s;


   return 0;
}