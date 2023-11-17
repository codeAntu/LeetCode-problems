#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

class Solution {
  public:
   int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
      int count = 0;
      int ind = (ruleKey == "color") + (ruleKey == "name") * 2;
      for (auto& item : items) {
         if (item[ind] == ruleValue) count++;
      }
      return count;
   }
};

int main() {
   Solution s;

   return 0;
}
