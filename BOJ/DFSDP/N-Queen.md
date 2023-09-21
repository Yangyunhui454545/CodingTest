대각선인지 확인하는 로직이 어려웠다. <br> 
(x1 - x2) == (y2 - y1) || (x1 - x1) == (y1 - y2) 이면 대각선임 <br> 
그리고 n퀸 문제는 그래프 가지치기랑 똑같았다. <br> 
위에서부터 대각선, 가로랑 같은 방향이 아니면 됨 <br> 




```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {

    static int answer = 0;
    static int[] visit = new int[16];
    static Map<Integer, Integer> map = new HashMap<>();

    // 8 * 8 체스판
    // 퀸은 상하좌우, 대각선으로 칸 수에 관계없이 움직일 수 있다.
    // 크기가 n * n인 체스판 위에 퀸 N개가 서로 공격할 수 없게 놓는 경우의 수
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < N; i++) {
            map.put(i, 0);
        }
        for (int i = 0; i < N; i++) {
            visit[0] = i + 1;
            map.put(i, 1);
            new Solution().dfs(1, N);
            visit[0] = 0;
            map.put(i, 0);
        }

        System.out.println(answer);
    }

    //visit 배열 index는 y좌표
    //visit 배열 값은 x 좌표

    //map 안에 x좌표 넣어주기
    public void dfs(int depth, int N) {
        if (depth == N) {
            answer++;
            return;
        }
        //depth는 새로 넣을 y 좌쵸
        //j는 이미 들어간 y 좌쵸
        for (int i = 0; i < N; i++) { //x 좌표
            if (map.get(i) != 0) continue; // 직선인지 확인
            boolean check = true;
            for (int j = 0; j < depth; j++) {
                //대각선인지 확인
                if ((visit[j] - 1 - i) == (depth - j) || (visit[j] - 1 - i) == (j - depth)) {
                    check = false;
                    break;
                }
            }
            if (check) {
                visit[depth] = i + 1;
                map.put(i, 1);
                dfs(depth + 1, N);
                visit[depth] = 0;
                map.put(i, 0);
            }

        }
    }
}
