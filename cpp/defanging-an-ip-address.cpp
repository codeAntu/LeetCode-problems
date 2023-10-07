#include "iostream"
#include "math.h"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        int n = address.length();
        for (int i = 0; i < n; i++)
        {
            if (address[i] == '.')
            {
                ans += "[.]";
            }
            else
             ans += address[i];
        }
        return ans;   
    }
};

int main() {
    Solution s;


    return 0;
}


