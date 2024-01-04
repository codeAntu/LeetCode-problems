#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

// class Solution {
//   public:
//    int trap(vector<int>& height) {
//       int ans = 0;
//       int left = 0, right = 1;
//       vector<bool> next(height.size(), false);
//       int max = 0;

//       for (int i = height.size() - 1; i >= 0; i--) {
//          if (max >= height[i]) {
//             next[i] = true;
//          } else {
//             max = height[i];
//          }
//       }

//       while (right < height.size()) {
//          int maxHighIndex = left + 1;
//          int temp = right;
//          int minHight = 0;
//          int del1 = 0;
//          int del2 = 0;

//          while (temp < height.size()) {
//             if (height[temp] >= height[left]) {
//                maxHighIndex = temp;
//                del2 = 0;
//                break;
//             } else if (!next[temp]) {
//                maxHighIndex = temp;
//                del2 = 0;
//                break;
//             }
//             del1 += height[temp];
//             del2 += height[temp];
//             temp++;
//          }

//          minHight = min(height[left], height[maxHighIndex]);
//          int count = maxHighIndex - left - 1;
//          int del = del1 - del2;
//          ans += count * minHight - del;

//          left = maxHighIndex;
//          right = left + 1;
//       }

//       return ans;
//    }
// };

class Solution {
  public:
   int trap(vector<int>& height) {
      int left = 0, right = height.size() - 1;
      int leftMax = height[left];
      int rightMax = height[right];
      int ans = 0;
      while (left < right) {
         if (leftMax > rightMax) {
            right--;
            rightMax = max(rightMax, height[right]);
            ans += rightMax - height[right];
         } else {
            left++;
            leftMax = max(leftMax, height[left]);
            ans += leftMax - height[left];
         }
      }
      return ans;
   }
};

int main() {
   Solution s;
   vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

   int x = s.trap(height);
   cout << x << endl;
   // findNextGreaterElement(height);

   vector<bool> next(height.size(), false);
   int max = 0;

   return 0;
}
