#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

class Solution {
  public:
   vector<string> findWords(vector<string>& words) {
      vector<string> rows = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
      vector<string> ans;
      vector<int> m(26, 0);

      for (int i = 0; i < rows.size(); i++) {
         for (char c : rows[i]) {
            m[c - 'A'] = 1 << i;
         }
      }

      for (auto& word : words) {
         int r = 7;
         for (char c : word) {
            r &= m[toupper(c) - 'A'];
         }
         if (r) ans.push_back(word);
      }
      return ans;
   }
};

int main() {
   Solution s;

   return 0;
}
