#include <unordered_map>

#include "vector"

using namespace std;

class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    int max_length = 0;
    int count = 0;
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++) {
      count += (nums[i] == 1) ? 1 : -1;

      if (count == 0) {
        max_length = max(max_length, i + 1);
      } else if (m.find(count) != m.end()) {
        max_length = max(max_length, i - m[count]);
      } else {
        m[count] = i;
      }
    }
    return max_length;
  }
};

int main() {
  Solution s;

  return 0;
}