#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

// done

class Solution {
public:
   int majorityElement(vector<int>& nums) {
      int count = 0 , element = 0;

      for (int i = 0; i < nums.size(); i++)
      {
         if (count == 0) element = nums[i];
         element == nums[i] ? count++ : count--;
      }
      return element;
   }
    int majorityElement(vector<int>& nums) {
      int count = 0 , element = 0;

      for (int i = 0; i < nums.size(); i++)
      {
         if (count == 0) element = nums[i];
        if( element == nums[i]) count++;
        else count--;
      }
      return element;
   }
};

int main() {
   Solution s;


   return 0;
}