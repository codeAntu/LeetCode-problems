
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
   int numberOfBeams(vector<string>& bank) {
      int rows = bank.size();
      int cols = bank[0].size();
      int thisRow = 0;
      int prevRow = 0;
      int count = 0;

      for (int i = 0; i < rows; i++) {
         for (int j = 0; j < cols; j++) {
            if (bank[i][j] == '1') {
               thisRow++;
            }
         }
         if (thisRow) {
            count += thisRow * prevRow;
            prevRow = thisRow;
            thisRow = 0;
         }
      }
      return count;
   }
};

int main() {
   Solution s;

   return 0;
}