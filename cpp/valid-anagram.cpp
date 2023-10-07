#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   bool isAnagram(string s, string t) {
      int arr[26] = { 0 };

      for (char c : s) arr[c - 'a']++;
      for (char c : t) arr[c - 'a']--;

      for (int num : arr)
         if (num) return false;
      return true;
   }
};
int main() {
   Solution s;
   cout << s.isAnagram("anagram", "nagaram");

   return 0;
}