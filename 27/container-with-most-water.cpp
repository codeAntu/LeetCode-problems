#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   int maxArea(vector<int>& height) {
      int i = 0, j = height.size() - 1;
      int area = 0, temp = 0;
      int a, b;
      while (i < j)
      {
         a = height[i];
         b = height[j];
         temp = (a > b ? b : a) * (j - i);
         if (area < temp) area = temp;
         cout << i << " " << j << " " << area << endl;

         if (a > b) j--;
         else i++;
      }
      return area;
   }
};

int main() {
   Solution s;
   vector<int> arr = { 1,8,6,2,5,4,8,3,7 };
   s.maxArea(arr);

   return 0;
}