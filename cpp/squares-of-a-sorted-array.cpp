#include <iostream>
#include <vector>

class Solution {
 public:
   std::vector<int> sortedSquares(std::vector<int>& nums) {
      int n = nums.size();
      std::vector<int> res(n);
      int i = 0, j = n - 1;
      for (int k = n - 1; k >= 0; k--) {
         if (abs(nums[i]) > abs(nums[j])) {
            res[k] = nums[i] * nums[i];
            i++;
         } else {
            res[k] = nums[j] * nums[j];
            j--;
         }
      }
      return res;
   }
};

int main() {
   Solution s;

   int arr[] = {-4, -1, 0, 3, 10};
    std::vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::vector<int> res = s.sortedSquares(nums);
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;

   return 0;
}