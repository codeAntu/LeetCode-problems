
#include <deque>
#include <iostream>
#include <string>

using namespace std;

string minimizeString(string S) {
  for (int i = 0; i < S.length() - 1; i++) {
    if (S[i] == '1' && S[i + 1] == '0') {
      return "0";
    }
  }
  return S;
}

int main() {
  string S;
  cin >> S;

  string result = minimizeString(S);
  cout << result << endl;

  return 0;
}
