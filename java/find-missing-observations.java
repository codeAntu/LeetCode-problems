class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int m = rolls.length;
        int sum = 0;
        for (int roll : rolls) {
            sum += roll;
        }
        int total = mean * (m + n);
        int remaining = total - sum;
        if (remaining < n || remaining > 6 * n) {
            return new int[0];
        }
        int[] ans = new int[n];
        int avg = remaining / n;
        int extra = remaining % n;
        for (int i = 0; i < n; i++) {
            ans[i] = avg + (i < extra ? 1 : 0);
        }
        return ans;    
    }
}