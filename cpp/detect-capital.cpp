
#include <string>

class Solution {
public:
  bool detectCapitalUse(std::string word) {
    bool isAllUpper = true;
    bool isAllLower = true;
    bool isFirstUpper = true;
    bool isOtherUpper = false;

    for (int i = 0; i < word.length(); i++) {
      if (word[i] >= 'A' && word[i] <= 'Z') {
        isAllLower = false;
        if (i == 0)
          isFirstUpper = true;
        else
          isOtherUpper = true;
      } else {
        isAllUpper = false;
      }
    }

    return isAllUpper || isAllLower || (isFirstUpper && !isOtherUpper);
  }
};
