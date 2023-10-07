#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
   string interpret(string command) {
      string result = "";
      for (int i = 0; i < command.size() ; i++) {
         if(command[i] == 'G')
            result += 'G';
         else if (command[i] == '(' && command[i + 1] == ')')
            result += 'o';
         else if (command[i] == '(' && command[i + 1] == 'a')
            result += "al";
         else
            continue;   
      }
      return result;
   }
};

int main() {
   Solution s;


   return 0;
}