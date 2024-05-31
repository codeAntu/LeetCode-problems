#include "vector"

using namespace std;

class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    int n = nums.size();
    int xorResult = 0;
    int bit = 1;
    for (int num : nums) {
      xorResult ^= num;
    }

    while ((xorResult & bit) == 0) {
      bit <<= 1;
    }

    int a = 0, b = 0;
    for (int num : nums) {
      if ((num & bit) == 0) {
        a ^= num;
      } else {
        b ^= num;
      }
    }

    return {a, b};
  }
};

int main() {
  Solution s;

  return 0;
}