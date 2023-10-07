#include "iostream"
#include "math.h"
#include "vector"
#include "map"
#include"greatest-common-divisor-of-strings.exe"

using namespace std;

class Solution {
public:
   string gcdOfStrings(string str1, string str2) {
      return (str1 + str2 == str2 + str1) ?
         str1.substr(0, gcd(size(str1), size(str2))) : "";
   }
};



int main() {
   Solution s;

   string s1 = "LEET", s2 = "CODE";

   cout << s.gcdOfStrings(s1, s2);

   return 0;
}