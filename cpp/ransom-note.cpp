#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   bool canConstruct(string ransomNote, string magazine) {
      int arr[26] = { 0 };

      for (char c : ransomNote) {
         arr[c - 'a']++;
      }

      for (char c : magazine) {
         arr[c - 'a']--;
      }
      for (int i = 0; i < 26; i++){
         if (arr[i] > 0) return false;
      }
      return true;
   }
};

int main() {
   Solution s;


   return 0;
}