#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include"set"
#include "stdlib.h"

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   bool closeStrings(string word1, string word2) {
      vector<int>arr1(26, 0), arr2(26, 0);
      vector< bool>  s1(26, 0), s2(26, 0);

      for (char c : word1) {
         arr1[c - 'a']++;
         s1[c - 'a'] = 1;
      }
      for (char c : word2) {
         arr2[c - 'a']++;
         s2[c - 'a'] = 1;

      }
      sort(arr1.begin(), arr1.end());
      sort(arr2.begin(), arr2.end());

      return s1 == s2 && arr1 == arr2;
   }
};

int main() {
   Solution s;

   s.closeStrings("abc", "bca");


   return 0;
}