#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:

   bool is_vow(char& c) {
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
      return false;
   }
   int maxVowels(string s, int k) {
      int i = 0, count = 0, max;
      while (i < k) {
         if (is_vow(s[i])) count++;
         i++;
      }
      max = count;

      for (i = k; i < s.length(); i++) {
         if (is_vow(s[i])) count++;
         if (is_vow(s[i - k])) count--;
         if (count > max) max = count;
      }
      return max;
   }
};

int main() {
   Solution s;

s.maxVowels("abciiidef",3);

   return 0;
}