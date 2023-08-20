#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include"unordered_map"
using namespace std;

class Solution {
public:
   bool isIsomorphic(string s, string t) {
      unordered_map <char, char> map1, map2;
      int n = s.length();

      for (int i = 0; i < n; i++)
      {
         if (map1.find(s[i] ) == map1.end())
            map1[s[i]] = t[i];
         else if (map1[s[i]] != t[i]) {
            return false;
         }
          if (map2.find(t[i] ) == map2.end())
            map2[t[i]] = s[i];
         else if (map2[t[i]] != s[i]) {
            return false;
         }
      }


      return true;
   }
};

class Solution {
public:
   bool isIsomorphic(string s, string t) {
      unordered_map <char, char> map1, map2;
      int n = s.length();

      for (int i = 0; i < n; i++)
      {
         if (map1.find(s[i] ) == map1.end())
            map1[s[i]] = t[i];
         else if (map1[s[i]] != t[i]) {
            return false;
         }
          if (map2.find(t[i] ) == map2.end())
            map2[t[i]] = s[i];
         else if (map2[t[i]] != s[i]) {
            return false;
         }
      }


      return true;
   }
};

class Solution {
public:
   bool isIsomorphic(string s, string t) {
      int n = s.length();
      int m1[256] = {0}, m2[256] = {0};
      for (int i = 0; i < n; i++)
      {
         if (m1[s[i]] != m2[t[i]]) {
            return false;
         }
         m1[s[i]] = i + 1;
         m2[t[i]] = i + 1;
      }
      return true;
   }
};

int main() {
   Solution s;


   return 0;
}