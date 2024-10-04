#include <algorithm>
#include "vector"

using namespace std;

class Solution {
public:
  long long dividePlayers(vector<int>& skill) {
    sort(skill.begin(), skill.end());

    long long res = 0;
    int n = skill.size();
    int skillSum = skill[0] + skill[n - 1];

    for (int i = 0; i < n / 2; i++) {
      if (skill[i] + skill[n - i - 1] != skillSum) {
        return -1;
      }
      res += skill[i] * skill[n - i - 1];
    }

    return res;
  }
};

int main() {
  Solution s;

  return 0;
}