#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   bool checkIfPangram(string sentence) {
      int arr[26] = { 0 };
      int n = sentence.length();

      for (int i = 0; i < n; i++)
      {
         arr[sentence[i] - 'a']++;
      }

      for (int i = 0; i < 26; i++)
      {
         if (arr[i] == 0) return false;
      }

      return true;

   }
};

int main() {
   Solution s;


   return 0;
}