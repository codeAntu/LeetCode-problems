#include "iostream"
#include "map"
#include "math.h"
#include "vector"
using namespace std;

// class Solution {
//   public:
//    string restoreString(string s, vector<int>& indices) {
//       map<int, char> m;
//       int len = s.length();
//       string res = "";
//       for (int i = 0; i < len; i++) {
//          m[indices[i]] = s[i];
//       }
//       for (int i = 0; i < len; i++) {
//          res += m[i];
//       }
//       return res;
//    }
// };

class Solution {
  public:
   string restoreString(string s, vector<int>& indices) {
      int len = s.length();
      vector<char> res(len);
      string str = "";
      for (int i = 0; i < len; i++) {
         res[indices[i]] = s[i];
      }
      for (auto c : res) {
         str += c;
      }
      return str;
   }
};

int main() {
   Solution s;

   return 0;
}
