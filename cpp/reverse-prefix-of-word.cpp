#include <string>

#include "math.h"

using namespace std;
class Solution {
public:
  string reverse(string word) {
    for (int i = 0; i < word.size() / 2; i++) {
      swap(word[i], word[word.size() - i - 1]);
    }
    return word;
  }
  string reversePrefix(string word, char ch) {
    for (int i = 0; i < word.size(); i++) {
      if (word[i] == ch) {
        return reverse(word.substr(0, i + 1)) + word.substr(i + 1);
      }
    }
    return word;
  }
};

int main() {
  Solution s;

  return 0;
}