#include <sstream>

#include "iostream"
#include "map"
#include "math.h"
#include "vector"

using namespace std;

class Solution {
public:
  int isPrefixOfWord(string sentence, string searchWord) {
    istringstream sstream(sentence);
    string word;
    int i = 1;

    while (sstream >> word) {
      if (word.find(searchWord) == 0) {
        return i;
      }
      i++;
    }

    return -1;
  }
};

int main() {
  Solution s;

  return 0;
}