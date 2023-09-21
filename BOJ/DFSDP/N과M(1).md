for문을 두번 넣을 생각하지 말고 dfs에게 전부 위임하자 <br>
까먹었던 dfs 상기 완료 <br> 
dfs는 visit 배열을 계속 갱신한다는 걸 잊지 말자 <br> 
그리고 if로 재귀 끊어내기 <br> 

```java
import java.io.*;
import java.util.*;

class Solution {

    static int[] visit = new int[9];

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int N = Integer.parseInt(stringTokenizer.nextToken());
        int M = Integer.parseInt(stringTokenizer.nextToken());
        new Solution().dfs("", N, M);
    }

    public void dfs(String arr, int N, int M) {
        if (arr.length() == M) {
            for (int i = 0; i < arr.length(); i++) {
                System.out.print(arr.charAt(i) + " ");
            }
            System.out.println();
            return;
        }
        for (int i = 1; i <= N; i++) {
            if (visit[i] == 1) continue;
            visit[i] = 1;
            dfs(arr + i, N, M);
            visit[i] = 0;
        }
    }
}
```
