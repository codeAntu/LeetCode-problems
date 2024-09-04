class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {

        Set<String> set = new HashSet<>();
        for (int[] obstacle : obstacles) {
            set.add(obstacle[0] + " " + obstacle[1]);
        }

        int[][] directions = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direction = 0;
        int x = 0, y = 0;
        int max = 0;

        for (int command : commands) {
            if (command == -2) {
                direction = (direction + 3) % 4;
            } else if (command == -1) {
                direction = (direction + 1) % 4;
            } else {
                int[] currentDirection = directions[direction];
                for (int i = 0; i < command; i++) {
                    int nextX = x + currentDirection[0];
                    int nextY = y + currentDirection[1];
                    if (set.contains(nextX + " " + nextY)) {
                        break;
                    }
                    x = nextX;
                    y = nextY;
                    max = Math.max(max, x * x + y * y);
                }
            }
        }

        return max;

    }
}