class Solution {
public:
  long long minEnd(int n, int x) {
    long ans = x;
    long pos = 1;
    long rem = n - 1;

    while (rem) {
      if (!(x & pos)) {
        ans |= (rem & 1) * pos;
        rem >>= 1;
      }
      pos <<= 1;
    }

    return ans;
  }
};

int main() {
  Solution s;

  return 0;
}