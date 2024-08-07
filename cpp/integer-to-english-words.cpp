#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  string numberToWords(int num) {
    string num1[] = {"",        "One",     "Two",       "Three",    "Four",
                     "Five",    "Six",     "Seven",     "Eight",    "Nine",
                     "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
                     "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    string num2[] = {"",      "",      "Twenty",  "Thirty", "Forty",
                     "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string x[] = {"", "Thousand", "Million", "Billion"};
    string res = "";

    for (int i = 0; i < 4; i++) {
      int n = num % 1000;
      num /= 1000;
      if (n == 0) continue;
      string temp = "";
      if (n / 100 > 0) {
        temp += num1[n / 100] + " Hundred";
      }
      n %= 100;
      if (temp != "" && n != 0) temp += " ";
      if (n < 20) {
        temp += num1[n];
      } else {
        temp += num2[n / 10] + (n % 10 == 0 ? "" : " " + num1[n % 10]);
      }
      if (temp != "" && i != 0) {
        temp += " " + x[i];
      }
      if (res != "") {
        res = temp + " " + res;
      } else {
        res = temp;
      }
    }

    return res == "" ? "Zero" : res;
  }
};
int main() {
  Solution s;

  return 0;
}