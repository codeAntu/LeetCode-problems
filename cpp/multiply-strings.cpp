#include <string>

#include "math.h"
#include "vector"

using namespace std;

// public String multiply(String num1, String num2) {
//     int m = num1.length(), n = num2.length();
//     int[] pos = new int[m + n];

//     for(int i = m - 1; i >= 0; i--) {
//         for(int j = n - 1; j >= 0; j--) {
//             int mul = (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
//             int p1 = i + j, p2 = i + j + 1;
//             int sum = mul + pos[p2];

//             pos[p1] += sum / 10;
//             pos[p2] = (sum) % 10;
//         }
//     }

//     StringBuilder sb = new StringBuilder();
//     for(int p : pos) if(!(sb.length() == 0 && p == 0)) sb.append(p);
//     return sb.length() == 0 ? "0" : sb.toString();
// }

// Like this

class Solution {
public:
  string multiply(string num1, string num2) {
    int m = num1.size(), n = num2.size();
    vector<int> pos(m + n, 0);

    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        int mul = (num1[i] - '0') * (num2[j] - '0');
        int p1 = i + j, p2 = i + j + 1;
        int sum = mul + pos[p2];

        pos[p1] += sum / 10;
        pos[p2] = (sum) % 10;
      }
    }

    string result = "";
    for (int p : pos)
      if (!(result.empty() && p == 0)) result += to_string(p);
    return result.empty() ? "0" : result;
  }
};

// class Solution {
// public:
//   string multiply(string num1, string num2) {
//     int n = num1.size();
//     int m = num2.size();
//     vector<int> res(n + m, 0);
//     for (int i = n - 1; i >= 0; i--) {
//       for (int j = m - 1; j >= 0; j--) {
//         int mul = (num1[i] - '0') * (num2[j] - '0');
//         int sum = mul + res[i + j + 1];
//         res[i + j + 1] = sum % 10;
//         res[i + j] += sum / 10;
//       }
//     }
//     string result = "";
//     for (int i = 0; i < n + m; i++) {
//       if (result.empty() && res[i] == 0) continue;
//       result += to_string(res[i]);
//     }
//     return result.empty() ? "0" : result;
//   }
// };

int main() {
  Solution s;

  return 0;
}