#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   bool wordPattern(string pattern, string s) {
      map<char, string> m;
      map<string, char> m2;

      vector<string> v;
      string temp = "";
      for (int i = 0; i < s.length(); i++) {
         if (s[i] == ' ') {
            v.push_back(temp);
            temp = "";
         }
         else {
            temp += s[i];
         }
      }
      v.push_back(temp);

      if (pattern.length() != v.size()) return false;
      
      for (int i = 0; i < pattern.length(); i++) {
         if (m.find(pattern[i]) == m.end()) {
            m[pattern[i]] = v[i];
         }
         else {
            if (m[pattern[i]] != v[i]) return false;
         }
      }

      for (int i = 0; i < v.size(); i++) {
         if (m2.find(v[i]) == m2.end()) {
            m2[v[i]] = pattern[i];
         }
         else {
            if (m2[v[i]] != pattern[i]) return false;
         }
      }

      return true;
   }
};

int main() {
   Solution s;


   return 0;
}