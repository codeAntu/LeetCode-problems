#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int calPoints(vector<string>& operations) {
      int n = operations.size();
      vector<int> nums;
      int sum = 0, i = -1;
      for (string s : operations)
      {
         if (s[0] == '+')
         {
            nums.push_back(nums[i] + nums[i - 1]);
            i++;

         } else if (s[0] == 'D')
         {
            nums.push_back(2 * nums[i]);
            i++;
         } else if (s[0] == 'C')
         {
            sum -= nums[i];
            nums.pop_back();
            i--;
            continue;
         } else {
            nums.push_back(atoi(s.c_str()));
            i++;
         }
         sum += nums[i];
      }
      return sum;
   }
};


int main() {
   Solution s;


   return 0;
}