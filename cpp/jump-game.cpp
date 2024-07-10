#include "vector"

using namespace std;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    int indx = n - 1;

    for (int i = n - 2; i >= 0; i--) {
      if (i + nums[i] >= indx) {
        indx = i;
      }
    }

    return indx == 0;
  }
};

int main() {
  Solution s;

  return 0;
}