#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i = m - 1;
      int j = n - 1;
      int k = m + n - 1;

      while (i >= 0 && j >= 0)
      {
         if (nums1[i] > nums2[j])
         {
            nums1[k] = nums1[i];
            i--;
         } else {
            nums1[k] = nums2[j];
            j--;
         }
         k--;
      }
      if (i < 0)
      {
         while (j >= 0)
         {
            nums1[k] = nums2[j];
            j--;
            k--;
         }
      }
   }
};

int main() {
   Solution s;

   vector<int> arr;
   arr.push_back(2);

   s.merge(arr, 4, arr, 5);



   return 0;
}