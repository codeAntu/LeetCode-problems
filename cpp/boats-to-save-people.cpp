#include <algorithm>
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int boats = 0;
    int i = 0, j = people.size() - 1;

    while (i <= j) {
      if (people[i] + people[j] <= limit) {
        i++;
      }
      j--;
      boats++;
    }

    return boats;
  }
};

int main() {
  Solution s;

  return 0;
}