
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int slow = 0;
    int fast = 0;
    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);
    slow = 0;
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
  }
};

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         int slow = n;
//         int fast = n;
//         do {
//             slow = nums[slow - 1];
//             fast = nums[nums[fast - 1] - 1];
//         } while (slow != fast);
//         slow = n;
//         while (slow != fast) {
//             slow = nums[slow - 1];
//             fast = nums[fast - 1];
//         }
//         return slow;
//     }
// };

int main() {
  Solution s;

  return 0;
}