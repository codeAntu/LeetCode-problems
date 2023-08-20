#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   bool isIsomorphic(string s, string t) {
      int n = s.length();
      map<char, char> map1 = {}, map2 = {};
      for (int i = 0; i < n; i++)
      {
         if (map1[s[i]] != t[i] | map2[t[i]] != s[i]) return false;
         map1[s[i]] = t[i];
         map2[t[i]] = s[i];
      }
      return true;
   }
};

int main() {
   Solution s;


   return 0;
}