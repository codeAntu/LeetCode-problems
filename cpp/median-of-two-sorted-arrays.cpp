#include "math.h"
#include "vector"

using namespace std;

// class Solution {
// public:
//   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//     int n = nums1.size();
//     int m = nums2.size();

//     int l = (n + m) / 2;

//     int i = 0;
//     int j = 0;

//     int prev = 0;
//     int curr = 0;

//     while (i + j <= l) {
//       prev = curr;
//       if (i < n && (j >= m || nums1[i] < nums2[j])) {
//         curr = nums1[i];
//         i++;
//       } else {
//         curr = nums2[j];
//         j++;
//       }
//     }

//     if ((n + m) % 2 == 0) {
//       return (prev + curr) / 2.0;
//     } else {
//       return curr;
//     }

//     return 0;
//   }
// };

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();

    if (n > m) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int l = (n + m + 1) / 2;

    int left = 0;
    int right = n;

    while (true) {
      int i = left + (right - left) / 2;
      int j = l - i;

      int nums1Left = i > 0 ? nums1[i - 1] : INT_MIN;
      int nums1Right = i < n ? nums1[i] : INT_MAX;
      int nums2Left = j > 0 ? nums2[j - 1] : INT_MIN;
      int nums2Right = j < m ? nums2[j] : INT_MAX;

      if(nums1Left <= nums2Right && nums2Left <= nums1Right) {
        if ((n + m) % 2 == 0) {
          return (max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) / 2.0;
        } else {
          return max(nums1Left, nums2Left);
        }
      } else if (nums1Left > nums2Right) {
        right = i - 1;
      } else {
        left = i + 1;
      }

    }
    return 0;
  }
};

int main() {
  Solution s;

  return 0;
}