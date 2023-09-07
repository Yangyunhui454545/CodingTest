import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int solution(int[][] maps) {
        int answer = Integer.MAX_VALUE;
        boolean flag = false;
        int meX = 0;
        int meY = 0;

        int enemyY = maps.length - 1;
        int enemyX = maps[0].length - 1;

        int[] y = {1, 0, -1, 0};
        int[] x = {0, -1, 0, 1};

        int[][] visit = new int[enemyY + 1][enemyX + 1];
        visit[0][0] = 1;


        Queue<Position> queue = new LinkedList<>();
        queue.add(new Position(meY, meX, 1));
        while (!queue.isEmpty()) {
            Position p = queue.poll();
            for (int i = 0; i < 4; i++) {
                int ny = p.y + y[i];
                int nx = p.x + x[i];
                if (ny < 0 || ny > maps.length - 1 || nx < 0 || nx > maps[0].length - 1 || maps[ny][nx] == 0 || visit[ny][nx] == 1)
                    continue;
                visit[ny][nx] = 1;
                if (ny == enemyY && nx == enemyX) {
                    if (answer > p.dist + 1) {
                        flag = true;
                        answer = p.dist + 1;
                    }
                } else {
                    queue.add(new Position(ny, nx, p.dist + 1));
                }
            }
        }
        if (!flag) answer = -1;
        return answer;
    }

    class Position {
        int x;
        int y;
        int dist;

        public Position(int y, int x, int dist) {
            this.y = y;
            this.x = x;
            this.dist = dist;
        }
    }
}
