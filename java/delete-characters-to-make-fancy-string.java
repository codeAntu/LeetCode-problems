class Solution {
    public String makeFancyString(String s) {
        StringBuilder sb = new StringBuilder();
        int count = 1;
        char prev = s.charAt(0);
        sb.append(prev);
        for (int i = 1; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == prev) {
                count++;
            } else {
                count = 1;
                prev = c;
            }
            if (count < 3) {
                sb.append(c);
            }
        }
        return sb.toString();      
      }
}
