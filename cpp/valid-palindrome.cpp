#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;
// done
class Solution {
public:
   bool isPalindrome(string s) {
      int i = 0, j = s.length() - 1;

      while (i < j)
      {
         if (!isalnum(s[i]))
         {
            i++;
            continue;;
         }
         if (!isalnum(s[j]))
         {
            j--;
            continue;;
         }
         if (tolower(s[i]) != tolower(s[j]))
            return false;
         else{
            i++;
            j--;
         }
      }
      return true;

   }
};

int main() {
   Solution s;
   char q= 'a';
   cout<< s.isPalindrome("A man, a plan, a canal: Panama");

   return 0;
}