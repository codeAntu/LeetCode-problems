#include "algorithm"
#include "iostream"
#include "map"
#include "math.h"
#include "unordered_map"
#include "vector"

using namespace std;

class Solution {
  public:
   vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> res;
      unordered_map<string, vector<string>> m;

      for (string s : strs) {
         string t = s;
         sort(t.begin(), t.end());
         m[t].push_back(s);
      }

      for (auto a : m) {
         res.push_back(a.second);
      }

      return res;
   }
};

int main() {
   Solution s;

   return 0;
}
