#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

// done 
class Solution {
public:
   string convertToTitle(int columnNumber) {
      string title ;
      while (columnNumber)
      {
         title = char(--columnNumber % 26 + 'A') + title;
         columnNumber /=  26;
      }
      return title;
   }
};

int main() {
   Solution s;


   return 0;
}