#include "vector"
using namespace std;

class Solution {
public:
  bool isOneBitCharacter(vector<int>& bits) {
    int size = bits.size();
    int i = 0;

    while (i < size - 1) {
      if (bits[i] == 1) {
        i += 2;
      } else {
        i++;
      }
    }
    return i == size - 1;
  }
};

int main() {
  Solution s;

  return 0;
}