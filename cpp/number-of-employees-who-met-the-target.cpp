#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
      int n=  hours.size();
      int count = 0;
      for (int i = 0; i < n; i++)
      {
         if (hours[i] >= target)
         {
            count++;
         }
         
      }
      return count;
   }
};

int main() {
   Solution s;


   return 0;
}