#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:

   bool isVowel(char c) {
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
         c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
      {
         return true;
      }
      return false;
   }
   string reverseVowels(string s) {
      int len = s.length();
      for (int i = 0, j = len - 1; i <= j; i++, j--)
      {
         while (!isVowel(s[i]) && i < j) {
            i++;
         }
         while (!isVowel(s[j]) && i < j) {
            j--;
         }
         if (i == j) return s;
         swap(s[i], s[j]);
      }
      return s;
   }
};

int main() {
   Solution s;

   cout << s.reverseVowels("hello");
   return 0;
}