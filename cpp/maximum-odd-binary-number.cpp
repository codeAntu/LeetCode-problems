

#include <string>
using namespace std;

class Solution {
 public:
   string maximumOddBinaryNumber(string s) {
      int oneCount = 0;
      string result = "";
      int i = 0;
      for (int i = 0; i < s.size(); i++) {
         if (s[i] == '1') {
            result += "1";
            oneCount++;
         }
      }
      result.pop_back();
      for (i = oneCount; i < s.size(); i++) {
         result += "0";
      }

      result += "1";

      return result;
   }
};

int main() {
   Solution s;

   return 0;
}