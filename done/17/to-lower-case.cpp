#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   string toLowerCase(string s) {
      for (char& c : s)
         if (c >= 'A' && c <= 'Z')
            c = c | ' ';
      return s;
   }
};

int main() {
   Solution s;


   return 0;
}