#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
  int maxDiff(int num) {
    string s1 = to_string(num);
    string s2 = s1;

    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] != '9') {
        char target = s1[i];
        replace(s1.begin(), s1.end(), target, '9');
        break;
      }
    }

    for (int i = 0; i < s2.size(); i++) {
      char c = s2[i];
      
      if (i == 0) {
        if (c != '1') {
          replace(s2.begin(), s2.end(), c, '1');
          break;
        }
      } else {
        if (c != '0' && c != s2[0]) {
          replace(s2.begin(), s2.end(), c, '0');
          break;
        }
      }
    }

    return stoi(s1) - stoi(s2);
  }
};

int main() {
  Solution s;
  // Add test cases here
  cout << s.maxDiff(555) << endl;  // Expected: 888
  cout << s.maxDiff(9) << endl;    // Expected: 8
  return 0;
}