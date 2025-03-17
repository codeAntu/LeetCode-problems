#include <unordered_map>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"


using namespace std;

class Solution {
public:
  bool divideArray(vector<int>& nums) {
    unordered_map<int, int> count;
    for (int num : nums) {
      count[num]++;
    }
    for (auto& pair : count) {
      if (pair.second % 2 != 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;

  return 0;
}